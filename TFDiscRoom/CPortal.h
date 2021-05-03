#pragma once
using namespace System::Drawing;
class CPortal {
	int X, Y;
	int anchoSprite, largoSprite;
	int indX = 0, indY;
	int dX=2, dY=2;
	int ancho = 40, largo = 40;
public:
	CPortal() {}
	~CPortal() {}
	CPortal(int X, int Y, int anchoImagen, int largoImagen) {
		this->X = X;
		this->Y = Y;
		this->anchoSprite = anchoImagen / 3;
		this->largoSprite = largoImagen / 4;
	}
	void Dibujar(Graphics^ g, Bitmap^ bmp, int indY) {
		Rectangle origen = Rectangle(indX*anchoSprite, indY*largoSprite, anchoSprite, largoSprite);
		Rectangle destino = Rectangle(X, Y, ancho, largo);
		g->DrawImage(bmp, destino, origen, GraphicsUnit::Pixel);
	}
	void GIF() {
		if (indY == 0) {
			indX++;
			if (indX > 2) indX = 0;
		}
		else if (indY == 1) {
			indX++;
			if (indX > 2) indX = 0;
		}
		else if (indY == 2) {
			indX++;
			if (indX > 2) indX = 0;
		}
		else if (indY == 3) {
			indX++;
			if (indX > 2) indX = 0;
		}
	}
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
	int getX() { return this->X; }
	int getY() { return this->Y; }
	int getAncho() { return this->ancho; }
	int getLargo() { return this->largo; }
};

