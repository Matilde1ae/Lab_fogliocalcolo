//
// Created by Matilde Giuliani on 23/04/25.
//

#ifndef UNTITLED43_CELLAMASSIMO_H
#define UNTITLED43_CELLAMASSIMO_H
#include <iostream>
#include "CellaFormula.h"
using namespace std;
class CellaMassimo : public CellaFormula {
public:
    explicit CellaMassimo (const string & nomeCella):
            CellaFormula (nomeCella){}
    void calcola (const vector <CellaValore *> celle) override {
        if (celle.empty ()) {
            valoreCalcolato = 0;
        }else{
            int max = celle[0]->getValore ();
            for (auto c:celle){
                if (c->getValore()>max){
                    max=c->getValore();
                }
                valoreCalcolato= max;
            }
        }
        // cout<<"Nome cella :"<<nomeCella<<"Minimo della cella: "<<valoreCalcolato<<endl;
    }

};
#endif //UNTITLED43_CELLAMASSIMO_H
