#pragma once
#include "CDisco.h"
#include "CPersonaje.h"
#include <vector>
using namespace std;

class CVecDisco {
	vector<CDisco*> arrDisco;
public:
	CVecDisco() {}
	~CVecDisco() {}
	//Esta funcion agrega los discos según su tipo
	void Agregar(int X, int Y, int dX, int dY, int anchoImagen, int largoImagen, int Tipo) {
		CDisco* objDisco;
		if (Tipo == 1) objDisco = new CDiscoSpinning(X, Y, dX, dY, anchoImagen, largoImagen, Tipo);
		else if (Tipo == 2)	objDisco = new CDiscoPersecutor(X, Y, dX, dY, anchoImagen, largoImagen, Tipo);
		else if (Tipo == 3) objDisco = new CDiscoLateral(X, Y, dX, dY, anchoImagen, largoImagen, Tipo);
		else if (Tipo == 4) objDisco = new CDiscoSpinning(X, Y, dX, dY, anchoImagen, largoImagen, Tipo);
		arrDisco.push_back(objDisco);
	}
	void Mover(int AnchoF, int LargoF, int pX, int pY) {
		for (int i = 0; i < arrDisco.size(); i++) {
			arrDisco.at(i)->Mover(AnchoF, LargoF, pX, pY);
		}
	}
	void Dibujar(Graphics^ g, Bitmap^ bmpSmallDisc, Bitmap^ bmpLateralDisc, Bitmap^ bmpPersecutorDisc, Bitmap^ bmpBigDisc) {
		for (int i = 0; i < arrDisco.size(); i++) {
			if (arrDisco.at(i)->getTipo() == 1) arrDisco.at(i)->Dibujar(g, bmpSmallDisc);
			else if (arrDisco.at(i)->getTipo() == 2) arrDisco.at(i)->Dibujar(g, bmpPersecutorDisc);
			else if (arrDisco.at(i)->getTipo() == 3) arrDisco.at(i)->Dibujar(g, bmpLateralDisc);
			else if (arrDisco.at(i)->getTipo() == 4) arrDisco.at(i)->Dibujar(g, bmpBigDisc);
		}
	}
	void GenerarColision(CPersonaje* Personaje) {
		for (int i = 0; i < arrDisco.size(); i++)
			if (!arrDisco.at(i)->getEliminado() && 
				(arrDisco.at(i)->HayColision(Personaje->getX(), Personaje->getY(), Personaje->getAncho(), Personaje->getLargo())
				|| Personaje->HayColision(arrDisco.at(i)->getX(),arrDisco.at(i)->getY(), arrDisco.at(i)->getAnchoImagen(), arrDisco.at(i)->getLargoImagen()))) {
				//
				arrDisco.at(i)->setEliminado(true);
				Personaje->setNroVidas(Personaje->getNroVidas() - 1);
				Personaje->setX(100);
				Personaje->setY(300);
			}
	}
	void EliminarDisco() {
		vector<CDisco*> Aux;
		for (int i = 0; i < arrDisco.size(); i++)
			if (!arrDisco.at(i)->getEliminado())
				Aux.push_back(arrDisco.at(i));

		arrDisco = Aux;
	}
};
