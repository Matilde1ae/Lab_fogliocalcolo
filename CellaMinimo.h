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
    CellaMinimo (const string & nomeCella, int dimensione,vector<CellaValore*>& celle):
            CellaFormula (nomeCella,dimensione, celle){
        if (celle.empty ()) {
            valoreCalcolato = 0;
        }else{
            valoreCalcolato= celle[0]->getValore ();
            for (auto & it:celle){
                if (it->getValore()<valoreCalcolato){
                    valoreCalcolato=it->getValore();
                }
            }
        }
        cout<<"Nome cella :"<<nomeCella<<"Minimo della cella: "<<valoreCalcolato<<endl;
    }
    void update () override {
        if (celle.empty ()) {
            valoreCalcolato = 0;
        }else{
            valoreCalcolato= celle[0]->getValore ();
            for (auto & it:celle){
                if (it->getValore()<valoreCalcolato){
                    valoreCalcolato=it->getValore();
                }
            }
        }
        cout<<"Nome cella :"<<nomeCella<<"Minimo della cella: "<<valoreCalcolato<<endl;
    }
};
#endif //UNTITLED43_CELLAMINIMO_H
