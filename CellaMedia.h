//
// Created by Matilde Giuliani on 23/04/25.
//

#ifndef UNTITLED43_CELLAMEDIA_H
#define UNTITLED43_CELLAMEDIA_H
#include <iostream>
#include "CellaFormula.h"
using namespace std;
class CellaMedia : public CellaFormula  {
public:
    explicit CellaMedia (const string & nomeCella):
            CellaFormula (nomeCella){}
    void calcola (const vector <CellaValore *> celle) override {
        if (celle.empty()) {
            valoreCalcolato = 0;
        } else {
            int somma = 0;
            for (Cella *c: celle) {
                somma += c->getValore();
            }
            valoreCalcolato = somma / celle.size();
        }
    }
};
#endif //UNTITLED43_CELLAMEDIA_H
