#pragma once
#include "CVectorDiscos.h"
#include "CPortal.h"
#include <fstream>

class CJuego {
private:
	CPersonaje* Personaje;
	CVecDisco* objVectorDisco;
	CPortal* objPortal;
	CJuego* objJuego;
	int anchof, largof;
	int contadorAux = 0;

	//Info Disco
	int X, Y;
	int dX, dY;
	int Ancho, Largo;
	int tipoDisco;
	int nDiscoSpinning;
	//
	int score;
	int segundos, milisegundos;
	//
	ofstream archivo;
	bool ColisionPortal = false;
	bool GameOver;
public:
	CJuego() {}
	~CJuego() {}
	CJuego(int score, int nivel, int nvidas, Bitmap^bmpPersonaje, Bitmap^ bmpSmallDisc, Bitmap^ bmpLateralDisc, Bitmap^ bmpPersecutorDisc, Bitmap^ bmpBigDisc, Bitmap^ bmpPortal, int width, int height) {
		Random^ r = gcnew Random(DateTime::Now.Ticks);
		//Ancho/Largo del formulario
		this->largof = height;
		this->anchof = width;
		//
		this->GameOver = false;
		//Iniciar Constructor de CPersonaje
		Personaje = new CPersonaje(100, 300, 30, 40, 4, 4, nvidas, bmpPersonaje->Width, bmpPersonaje->Height);
		//Iniciar Constructor de CVectorDisco
		objVectorDisco = new CVecDisco();
		//Constructor del Portal
		objPortal = new CPortal(r->Next(64, width - 100), r->Next(64, height - 100), bmpPortal->Width, (bmpPortal->Height));
		//Posicion Inicial de los disco;
		int startX = (anchof / 2) - ((bmpSmallDisc->Width / 3) / 2);
		int startY = (largof / 2) - ((bmpSmallDisc->Height) / 2);
		//Score
		this-> score = score;
		this-> segundos = score / 99;
		this-> milisegundos = score % 99;
		//Niveles
		// SmallDisc-Spinning = 1
		// PersecutorDisc = 2
		// LateralDisc = 3
		// BigDisc - Spinning = 4
		if (nivel == 1) {
			nDiscoSpinning = r->Next(20, 30);
			for (int i = 0; i < nDiscoSpinning; i++) {
				this->dX = r->Next(-3, 3);
				this->dY = r->Next(-3, 3);
				objVectorDisco->Agregar(startX, startY, dX, dY, bmpSmallDisc->Width, bmpSmallDisc->Height, 1);
			}
		}
		else if (nivel == 2) {
			nDiscoSpinning = r->Next(25, 30);
			for (int i = 0; i < nDiscoSpinning; i++) {
					this->dX = r->Next(-4, 4);
					this->dY = r->Next(-4, 4);
					objVectorDisco->Agregar(startX, startY, dX, dY, bmpSmallDisc->Width, bmpSmallDisc->Height, 1);			
				}
			for (int i = 0; i < nDiscoSpinning / 3; i++) {
				objVectorDisco->Agregar(startX, startY, dX, dY, bmpBigDisc->Width, bmpBigDisc->Height, 4);
			}
		}
		else if (nivel == 3) {
			nDiscoSpinning = r->Next(25, 35);
			for (int i = 0; i < nDiscoSpinning; i++) {
				this->dX = r->Next(-4, 4);
				this->dY = r->Next(-4, 4);
				objVectorDisco->Agregar(startX, startY, dX, dY, bmpSmallDisc->Width, bmpSmallDisc->Height, 1);
			}
			for (int i = 0; i < nDiscoSpinning / 3; i++) {
				this->dX = r->Next(-4, 4);
				this->dY = r->Next(-4, 4);
				objVectorDisco->Agregar(startX, startY, dX, dY, bmpBigDisc->Width, bmpBigDisc->Height, 4);
			}
		}
		else if (nivel == 4) {
			nDiscoSpinning = r->Next(25, 40);
			for (int i = 0; i < nDiscoSpinning; i++) {
				this->dX = r->Next(-5, 5);
				this->dY = r->Next(-5, 5);
				objVectorDisco->Agregar(startX, startY, dX, dY, bmpSmallDisc->Width, bmpSmallDisc->Height, 1);
			}
			for (int i = 0; i < nDiscoSpinning / 2; i++) {
				this->dX = r->Next(-5, 5);
				this->dY = r->Next(-5, 5);
				objVectorDisco->Agregar(startX, startY, dX, dY, bmpBigDisc->Width, bmpBigDisc->Height, 4);
			}
		}
		else if (nivel == 5) {
			nDiscoSpinning = r->Next(30, 50);
			for (int i = 0; i < nDiscoSpinning; i++) {
				this->dX = r->Next(-5, 5);
				this->dY = r->Next(-5, 5);
				objVectorDisco->Agregar(startX, startY, dX, dY, bmpSmallDisc->Width, bmpSmallDisc->Height, 1);
			}
			for (int i = 0; i < nDiscoSpinning / 2; i++) {
				this->dX = r->Next(-5, 5);
				this->dY = r->Next(-5, 5);
				objVectorDisco->Agregar(startX, startY, dX, dY, bmpBigDisc->Width, bmpBigDisc->Height, 4);
			}
		}
		//Persecutor
		objVectorDisco->Agregar(startX, startY, dX, dY, bmpPersecutorDisc->Width, bmpPersecutorDisc->Height, 2);
		//LateralDisc
		objVectorDisco->Agregar(64, 64, 6, 0, bmpLateralDisc->Width, bmpLateralDisc->Height, 3);
		objVectorDisco->Agregar((anchof - 64 - (bmpLateralDisc->Width / 3)), (largof - 64 - bmpLateralDisc->Height), -6, 0, bmpLateralDisc->Width, bmpLateralDisc->Height, 3);
		//
	}
	void Dibujar(int nivel, Graphics^g, Bitmap^bmpPersonaje, Bitmap^ bmpSmallDisc, Bitmap^ bmpLateralDisc, Bitmap^ bmpPersecutorDisc, Bitmap^ bmpBigDisc, Bitmap^ bmpFondo, Bitmap^ bmpMarco, Bitmap^ bmpPortal) {
		if (nivel == 1) {
			bmpFondo = gcnew Bitmap("BackGround1.png");
			bmpMarco = gcnew Bitmap("Frame1.png");
		}
		else if (nivel == 2) {
			bmpFondo = gcnew Bitmap("BackGround2.png");
			bmpMarco = gcnew Bitmap("Frame2.png");
		}
		else if (nivel == 3) {
			bmpFondo = gcnew Bitmap("BackGround3.png");
			bmpMarco = gcnew Bitmap("Frame3.png");
		}
		else if (nivel == 4) {
			bmpFondo = gcnew Bitmap("BackGround4.png");
			bmpMarco = gcnew Bitmap("Frame4.png");
		}
		else if (nivel == 5) {
			bmpFondo = gcnew Bitmap("BackGround5.png");
			bmpMarco = gcnew Bitmap("Frame5.png");
		}
		g->DrawImage(bmpFondo, 0, 0, anchof, largof);
		bmpMarco->MakeTransparent(bmpMarco->GetPixel(60, 60));
		g->DrawImage(bmpMarco, 0, 0, anchof, largof);
		g->DrawString("HP: " + Personaje->getNroVidas() + "/ LVL " + nivel, gcnew System::Drawing::Font("Arial", 14, FontStyle::Bold), Brushes::White, 5, 5);
		objVectorDisco->Dibujar(g, bmpSmallDisc, bmpLateralDisc, bmpPersecutorDisc, bmpBigDisc);
		Personaje->Dibujar(g, bmpPersonaje);
		Cronometro(g);
		Random^ r = gcnew Random(DateTime::Now.Ticks);
		//Agregar Persecutor Aleatoriamente
		if (r->Next(5, 50) == 25) {
			objVectorDisco->Agregar((anchof / 2) - ((bmpSmallDisc->Width / 3) / 2), (largof / 2) - ((bmpSmallDisc->Height) / 2), dX, dY, bmpPersecutorDisc->Width, bmpPersecutorDisc->Height, 2);
		}
		//Portal
		if ((score > 500 && nivel == 1) || (score > 1000 && nivel == 2) || (score > 1500 && nivel == 3) || (score > 2000 && nivel == 4) || (score > 2500 && nivel == 5)) {
			if (nivel<=5) {
				objPortal->Dibujar(g, bmpPortal, r->Next(0, 4));
				objPortal->GIF();
				if (Personaje->HayColision(objPortal->getX(), objPortal->getY(), objPortal->getAncho(), objPortal->getLargo()) == true) {
					ColisionPortal = true;
				}
			}
		}
	}
	void MoverPersonaje(Keys e, bool slowMode) {
		Personaje->Mover(anchof, largof, e, slowMode);
	}
	void MoverDisco(int z, int pX, int pY, bool slowMode, int contadorUsos) {
		if (contadorUsos >= z) {
			slowMode = false;
		}
		if (slowMode == true) {
			if (contadorAux == 5) {
				objVectorDisco->Mover(anchof, largof, Personaje->getX(), Personaje->getY());
				contadorAux = 0;
			}
			else {
				contadorAux++;
			}
		}
		else {
			objVectorDisco->Mover(anchof, largof, Personaje->getX(), Personaje->getY());
		}
		objVectorDisco->GenerarColision(Personaje);
		objVectorDisco->EliminarDisco();
		if (Personaje->getNroVidas() <= 0) {
			GameOver = true;
		}
		objPortal->Mover(anchof, largof, Personaje->getX(), Personaje->getY());
	}
	void Cronometro(Graphics^ g) {
		milisegundos++;
		if (milisegundos == 100) {
			milisegundos = 0;
			segundos++;
		}
		score += 1;
		g->DrawString("Time " + segundos + "." + milisegundos, gcnew Font("Arial", 14, FontStyle::Bold), Brushes::White, 550, 5);
		AgregarScore(segundos, milisegundos,score);
	}
	void AgregarScore(int segundos,int milisegundos,int sscore) {
		archivo.open("score.txt", fstream::app);
		archivo << segundos << "." << milisegundos << "|"<<sscore<<"|";
		archivo.close();
	}
	int getScore() { return this->score; }
	int getnVidas() { return this->Personaje->getNroVidas(); }
	bool getColision() { return this->ColisionPortal; }
	bool getGameover() { return this->GameOver; }
};