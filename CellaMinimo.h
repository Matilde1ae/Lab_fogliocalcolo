//
// Created by Matilde Giuliani on 23/04/25.
//

#ifndef UNTITLED43_CELLAMINIMO_H
#define UNTITLED43_CELLAMINIMO_H
#include <iostream>
#include "CellaFormula.h"
using namespace std;
class CellaMinimo : public CellaFormula {
public:
    CellaMinimo (const string & nomeCella):
            CellaFormula (nomeCella){}
    void calcola (const vector <CellaValore *> celle){
        if (celle.empty ()) {
            valoreCalcolato = 0;
        }else{
            int min = celle[0]->getValore ();
            for (auto c:celle){
                if (c->getValore()<min){
                    min=c->getValore();
                }
                valoreCalcolato= min;
            }
        }
        //cout<<"Nome cella :"<<nomeCella<<"Minimo della cella: "<<valoreCalcolato<<endl;
    }
};
#endif //UNTITLED43_CELLAMINIMO_H
