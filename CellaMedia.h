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
    CellaMedia (const string & nomeCella, int dimensione,vector<CellaValore*>& celle):
            CellaFormula (nomeCella,dimensione, celle){
        if (celle.empty ()){
            valoreCalcolato=0;
        }else {
            int somma = 0;
            for (Cella * c: celle){
                somma += c->getValore();
            }
            valoreCalcolato=somma/celle.size();
        }
       // cout<<"Nome della cella"<<nomeCella<<"Media"<<valoreCalcolato<<endl;
    }
    void update () override {
        if (celle.empty ()){
            valoreCalcolato=0;
        }else {
            int somma = 0;
            for (Cella * c: celle){
                somma += c->getValore();
            }
            valoreCalcolato=somma/celle.size ();
        }
       //cout<<"Nome della cella :"<<nomeCella<<"Media aggiornata:"<<valoreCalcolato<<endl;
    }
};
#endif //UNTITLED43_CELLAMEDIA_H
