#pragma once
using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;
class CPersonaje {
private:
	int X, Y;
	int dX, dY;
	int Ancho, Largo;
	int indX, indY;
	int anchoSprite, largoSprite;
	int NroVidas;
public:
	CPersonaje() {}
	~CPersonaje() {}
	CPersonaje(int X, int Y, int Ancho, int Largo, int dX, int dY, int nvidas, int anchoImagen, int largoImagen) {
		this->X = X;
		this->Y = Y;
		this->Ancho = Ancho;
		this->Largo = Largo;
		this->dX = dX;
		this->dY = dY;
		this->indX = 0;
		this->indY = 0;
		this->NroVidas = nvidas + 1;
		this->anchoSprite = anchoImagen / 12;
		this->largoSprite = largoImagen / 8;
	}
	void Dibujar(Graphics^ g, Bitmap^bmp) {
		//Coge el sprite de la imagen
		Rectangle origen = Rectangle(indX*anchoSprite, indY*largoSprite, anchoSprite, largoSprite);
		//Lo pone en pantalla
		Rectangle destino = Rectangle(X, Y, Ancho, Largo);
		g->DrawImage(bmp, destino, origen, GraphicsUnit::Pixel);
	}
	void Mover(int AnchoF, int LargoF, Keys  e, bool slowMode) {
		if (e == Keys::Right && X + dX + anchoSprite< AnchoF) { // HACIA LA DERECHA
			if (slowMode == true) {
				indY = 6;
			}
			else if (slowMode == false) {
				indY = 2;
			}
			indX++;
			if (indX >= 2) indX = 0;
			X += dX;
		}
		else if (e == Keys::Left && X - dX > 64) { // HACIA LA IZQUIERDA
			if (slowMode == true) {
				indY = 5;
			}
			else if (slowMode == false) {
				indY = 1;
			}
			indX++;
			if (indX >= 2) indX = 0;
			X -= dX;
		}
		else if (e == Keys::Down && Y + dY + largoSprite< LargoF + 5) { // HACIA ABAJO
			if (slowMode == true) {
				indY = 4;
			}
			else if (slowMode == false) {
				indY = 0;
			}
			indX++;
			if (indX >= 2) indX = 0;
			Y += dY;
		}
		else if (e == Keys::Up && Y - dY > 64 - (anchoSprite / 2)) { // HACIA ARRIBA
			if (slowMode == true) {
				indY = 7;
			}
			else if (slowMode == false) {
				indY = 3;
			}
			indX++;
			if (indX >= 2) indX = 0;
			Y -= dY;
		}
	}
	bool HayColision(int pX, int pY) {
		return pX >= X 
			&& pX <= X + Ancho 
			&& pY >= Y 
			&& pY <= Y + Largo;
	}
	bool HayColision(int pX, int pY, int pAncho, int pLargo) {
		return HayColision(pX, pY) || HayColision(pX + pAncho, pY) ||
			HayColision(pX, pY + pLargo) || HayColision(pX + pAncho, pY + pLargo);
	}
	int getNroVidas() { return this->NroVidas; }
	int getX() { return this->X; }
	int getY() { return this->Y; }
	int getAncho() { return this->Ancho; }
	int getLargo() { return this->Largo; }
	void setNroVidas(int NroVidas) { this->NroVidas = NroVidas; }
	void setX(int X) { this->X = X; }
	void setY(int Y) { this->Y = Y; }
};
