//
// Created by Matilde Giuliani on 23/04/25.
//

#ifndef UNTITLED43_CELLASOMMA_H
#define UNTITLED43_CELLASOMMA_H
#include <iostream>
#include "CellaFormula.h"
using namespace std;
class CellaSomma : public CellaFormula {
public:
    CellaSomma (const string & nomeCella, int dimensione,vector<CellaValore*>& celle):
    CellaFormula (nomeCella,dimensione, celle){
        int valore=0;
        for (Cella * c :celle) {
            valore+= c->getValore();
        }
        valoreCalcolato = valore;
        cout << "Nome cella: " << nomeCella << "Somma" << valore << endl;
    }

    void update () override {
        int valore=0;
        for (Cella * c :celle) {
            valore+= c->getValore();
        }
        valoreCalcolato = valore;
        cout << "Nome cella: " << nomeCella << "Somma aggiornata :" << valore << endl;
    }
};
#endif //UNTITLED43_CELLASOMMA_H
