#pragma once
#include "CJuego.h"
class CApp {
	int nivel = 1;
	CJuego* objJuego;
	CVecDisco* objVector;
	int nvidas;
	int anchof;
	int largof;
	int score = 0;
	int contadorUsos = 0;
public:
	CApp() {}
	~CApp() {}
	CApp(int nvidas, Bitmap^bmpPersonaje, Bitmap^ bmpSmallDisc, Bitmap^ bmpLateralDisc, Bitmap^ bmpPersecutorDisc, Bitmap^ bmpBigDisc, Bitmap^ bmpPortal, int width, int height) {
		this->nvidas = nvidas;
		this->anchof = width;
		this->largof = height;
		//Inciar en Nivel 1
		objJuego = new CJuego(score, 1, nvidas, bmpPersonaje, bmpSmallDisc, bmpLateralDisc, bmpPersecutorDisc, bmpBigDisc, bmpPortal, anchof, largof);
	}
	void Dibujar(Graphics^g, Bitmap^bmpPersonaje, Bitmap^ bmpSmallDisc, Bitmap^ bmpLateralDisc, Bitmap^ bmpPersecutorDisc, Bitmap^ bmpBigDisc, Bitmap^ bmpFondo, Bitmap^ bmpMarco, Bitmap^ bmpPortal) {
		if (objJuego->getGameover() == false) {
			objJuego->Dibujar(nivel, g, bmpPersonaje, bmpSmallDisc, bmpLateralDisc, bmpPersecutorDisc, bmpBigDisc, bmpFondo, bmpMarco, bmpPortal);
		}
	}
	void ComprobarPortal(Bitmap^ bmpPersonaje, Bitmap^ bmpSmallDisc, Bitmap^ bmpLateralDisc, Bitmap^ bmpPersecutorDisc, Bitmap^ bmpBigDisc, Bitmap^ bmpFondo, Bitmap^ bmpMarco, Bitmap^ bmpPortal) {
		if (objJuego->getColision() == true) {
			//Obtiene el score del anterior nivel en milisegundos
			score = objJuego->getScore();
			//
			nivel++;
			if (nivel == 1) {
				objJuego = new CJuego(score, nivel, nvidas, bmpPersonaje, bmpSmallDisc, bmpLateralDisc, bmpPersecutorDisc, bmpBigDisc, bmpPortal, anchof, largof);
				contadorUsos = 0;
			}
			else if (nivel == 2) {
				objJuego = new CJuego(score, nivel, nvidas, bmpPersonaje, bmpSmallDisc, bmpLateralDisc, bmpPersecutorDisc, bmpBigDisc, bmpPortal, anchof, largof);
				contadorUsos = 0;
			}
			else if (nivel == 3) {
				objJuego = new CJuego(score, nivel, nvidas, bmpPersonaje, bmpSmallDisc, bmpLateralDisc, bmpPersecutorDisc, bmpBigDisc, bmpPortal, anchof, largof);
				contadorUsos = 0;
			}
			else if (nivel == 4) {
				objJuego = new CJuego(score, nivel, nvidas, bmpPersonaje, bmpSmallDisc, bmpLateralDisc, bmpPersecutorDisc, bmpBigDisc, bmpPortal, anchof, largof);
				contadorUsos = 0;
			}
			else if (nivel == 5) {
				objJuego = new CJuego(score, nivel, nvidas, bmpPersonaje, bmpSmallDisc, bmpLateralDisc, bmpPersecutorDisc, bmpBigDisc, bmpPortal, anchof, largof);
				contadorUsos = 0;
			}
		}
	}
	void MoverPersonaje(Keys e, bool slowMode) {
		if (objJuego->getGameover() == false) {
			objJuego->MoverPersonaje(e, slowMode);
		}
	}
	void MoverDisco(int pX, int pY, bool slowMode) {
		if (objJuego->getGameover() == false) {
			objJuego->MoverDisco((2 * nivel) - 2, pX, pY, slowMode, contadorUsos);
		}
	}
	bool getGameover() { return this->objJuego->getGameover(); }
	int getNivel() { return this->nivel; }
	int getContadorUsos() { return this->contadorUsos; }
	void setContadorUsos(int N) { this->contadorUsos = N; }
};