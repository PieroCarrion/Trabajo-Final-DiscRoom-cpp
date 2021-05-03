#pragma once
#include <math.h>
using namespace System;
using namespace System::Drawing;

class CDisco {
protected:
	int X, Y;
	int dX, dY;
	int indX;
	int anchoSprite, largoSprite;
	int tipo;
	bool Eliminado;
public:
	CDisco() {}
	~CDisco() {}
	CDisco(int X, int Y, int dX, int dY, int anchoImagen, int largoImagen, int tipo) {
		this->X = X;
		this->Y = Y;
		this->dX = dX;
		this->dY = dY;
		this->indX = 0;
		this->anchoSprite = anchoImagen / 3;
		this->largoSprite = largoImagen / 1;
		this->tipo = tipo;
		this->Eliminado = false;
	}
	virtual void Mover(int AnchoF, int LargoF, int pX, int pY) = 0;
	virtual void Dibujar(Graphics^ g, Bitmap^ bmp) = 0;
	bool HayColision(int pX, int pY) {
		return pX >= X && pX <= X + anchoSprite && pY >= Y && pY <= Y + largoSprite;
	}
	bool HayColision(int pX, int pY, int pAncho, int pLargo) {
		return HayColision(pX, pY) || HayColision(pX + pAncho, pY) ||
			HayColision(pX, pY + pLargo) || HayColision(pX + pAncho, pY + pLargo);
	}
	int getX() { return this->X; }
	int getY() { return this->Y; }
	void setDx(int dX) { this->dX = dX; }
	void setDy(int dY) { this->dY = dY; }
	int getAnchoImagen() { return this->anchoSprite; }
	int getLargoImagen() { return this->largoSprite; }
	void setAnchoImagen(int anchoSprite) { this->anchoSprite = anchoSprite; }
	void setLargoImagen(int largoSprite) { this->largoSprite = largoSprite; }
	bool getEliminado() { return this->Eliminado; }
	void setEliminado(bool Eliminado) { this->Eliminado = Eliminado; }
	int getTipo() { return this->tipo; }
	void setTipo(int tipo) { this->tipo	= tipo; }
};

class CDiscoSpinning : public CDisco {
private:
public:
	CDiscoSpinning() {}
	CDiscoSpinning(int X, int Y, int dX, int dY, int anchoImagen, int largoImagen, int tipo) : CDisco(X, Y, dX, dY, anchoImagen, largoImagen, tipo) {}
	~CDiscoSpinning() {}
	void Mover(int AnchoF, int LargoF, int pX, int pY) {
		//..........................
		X += dX;
		Y += dY;
		//......
		//Sprite
		indX++;
		if (indX > 2) indX = 0;
		//
		if (X + dX < 64 || X + dX + anchoSprite > AnchoF - 64)
			dX *= -1;
		if (Y + dY < 64 || Y + dY + largoSprite > LargoF - 64)
			dY *= -1;
	}
	void Dibujar(Graphics^ g, Bitmap^ bmp) {
		Rectangle origen = Rectangle(anchoSprite*indX, 0, anchoSprite, largoSprite);
		Rectangle destino = Rectangle(X, Y, anchoSprite, largoSprite);
		bmp->MakeTransparent();
		g->DrawImage(bmp, destino, origen, GraphicsUnit::Pixel);
	}
};

class CDiscoPersecutor : public CDisco {
private:
public:
	CDiscoPersecutor() {}
	CDiscoPersecutor(int X, int Y, int dX, int dY, int anchoImagen, int largoImagen, int tipo) : CDisco(X, Y, dX, dY, anchoImagen, largoImagen, tipo) {}
	~CDiscoPersecutor() {}
	void Mover(int AnchoF, int LargoF, int pX, int pY) {
		dX = 4;
		dY = 4;
		indX++;
		//float distancia = sqrt((pX - X)*(pX - X) + (pY - Y)*(pY - Y));
		if (indX > 2) indX = 0;
		//
		if (pX != X) {
			float pendiente = (pY - Y) / (pX - X);
			float angulo = fabs(atan(pendiente));
			if (pX > X) {
				dX = fabs(dX*cos(angulo));
			}
			if (pX < X) {
				dX = -1* (fabs(dX*cos(angulo)));
			}
			if (pY > Y) {
				dY = fabs(dY*sin(angulo));
			}
			if (pY < Y) {
				dY = -1 * (fabs(dY*sin(angulo)));
			}
		}
		//.........
		X += dX;
		Y += dY;
		
	}
	void Dibujar(Graphics^ g, Bitmap^ bmp) {
		Rectangle origen = Rectangle(anchoSprite*indX, 0, anchoSprite, largoSprite);
		Rectangle destino = Rectangle(X, Y, anchoSprite, largoSprite);
		bmp->MakeTransparent();
		g->DrawImage(bmp, destino, origen, GraphicsUnit::Pixel);
	}
};
class CDiscoLateral :public CDisco {
private:
public:
	CDiscoLateral() {}
	CDiscoLateral(int X, int Y, int dX, int dY, int anchoImagen, int largoImagen, int tipo) : CDisco(X, Y, dX, dY, anchoImagen, largoImagen, tipo) {}
	~CDiscoLateral() {}
	void Mover(int AnchoF, int LargoF, int pX, int pY) {
		//Movimiento
		X += dX;
		Y += dY;
		//Sprite
		indX++;
		if (indX >= 2) indX = 0;
		//Rebote Eje X
		if (X + dX < 64) {
			dX = 0;
			dY = -6;
		}
		else if (X + dX + anchoSprite > AnchoF - 64) {
			dX = 0;
			dY = 6;
		}
		//Rebote Eje Y
		if (Y + dY < 64) {
			dY = 0;
			dX = 6;
		}
		else if (Y + dY + largoSprite > LargoF - 64) {
			dY = 0;
			dX = -6;
		}
		//
	}
	void Dibujar(Graphics^ g, Bitmap^ bmp) {
		Rectangle origen = Rectangle(anchoSprite*indX, 0, anchoSprite, largoSprite);
		Rectangle destino = Rectangle(X, Y, anchoSprite, largoSprite);
		bmp->MakeTransparent();
		g->DrawImage(bmp, destino, origen, GraphicsUnit::Pixel);
	}
};
