//
// Created by Matilde Giuliani on 23/04/25.
//

#ifndef UNTITLED43_CELLAFORMULA_H
#define UNTITLED43_CELLAFORMULA_H
#include <iostream>
#include "Cella.h"
#include "CellaValore.h"
#include <ncurses.h>
using namespace std;
class CellaFormula : public Cella {
public:
    CellaFormula (const string & nomeCella) : Cella (nomeCella),valoreCalcolato (0) {}
    int getValore () const override {
        return valoreCalcolato;
    }
    virtual void calcola (const vector <CellaValore *> celle) = 0;

    void showResult (int & riga) const {
        mvprintw (riga ++, 0, "Nome cella: %s, Valore Calcolato %d", nomeCella.c_str (),valoreCalcolato);
    }

protected:
    int valoreCalcolato;
};

#endif //UNTITLED43_CELLAFORMULA_H
