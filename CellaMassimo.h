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
    CellaMassimo (const string & nomeCella, int dimensione,vector<CellaValore*>& celle):
            CellaFormula (nomeCella,dimensione, celle){
        if (celle.empty ()) {
            valoreCalcolato = 0;
        }else{
            valoreCalcolato= celle[0]->getValore ();
            for (auto & it:celle){
                if (it->getValore()>valoreCalcolato){
                    valoreCalcolato=it->getValore();
                }
            }
        }
       cout<<"Nome cella :"<<nomeCella<<"Massimo della cella: "<<valoreCalcolato<<endl;
    }
    void update () override {
        if (celle.empty ()) {
            valoreCalcolato = 0;
        }else{
            valoreCalcolato= celle[0]->getValore ();
            for (auto & it:celle){
                if (it->getValore()>valoreCalcolato){
                    valoreCalcolato=it->getValore();
                }
            }
        }
        cout<<"Nome cella :"<<nomeCella<<"Massimo della cella: "<<valoreCalcolato<<endl;
    }
};
#endif //UNTITLED43_CELLAMASSIMO_H
