//
// Created by Matilde Giuliani on 30/04/25.
//

#ifndef UNTITLED43_FOGLIOCALCOLO_H
#define UNTITLED43_FOGLIOCALCOLO_H
#include <iostream>
#include <list>
#include "CellaValore.h"
#include "CellaFormula.h"
#include "CellaSomma.h"
using namespace std;
class FoglioCalcolo {
public:
    void addCelleValore (CellaValore * cella) {
        celleSelezionate.push_back(cella);
    }
    void removeCellaValore (CellaValore * cella) {
        celleSelezionate.remove (cella);
    }
    CellaSomma * getSomma () {
        CellaSomma * somma = new CellaSomma ("A", 1, 1);
        int valore=0;
        for (Cella * c :celleSelezionate) {
            valore+= c->getValore();
        }
        somma-> setValoreCalcolato (valore);
        return somma;
    }

private:
    list <CellaValore *> celleSelezionate;
};
#endif //UNTITLED43_FOGLIOCALCOLO_H
