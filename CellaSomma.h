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
    explicit CellaSomma (const string & nomeCella):
    CellaFormula (nomeCella){}
    void calcola (const vector<CellaValore *> celle) override {
        int somma = 0;
        for (Cella *c: celle) {
            somma += c->getValore();
        }
        valoreCalcolato = somma;
        // cout << "Nome cella: " << nomeCella << "Somma" << valore << endl;
    }
};
#endif //UNTITLED43_CELLASOMMA_H
