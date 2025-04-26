//
// Created by Matilde Giuliani on 23/04/25.
//

#ifndef UNTITLED43_CELLAFORMULA_H
#define UNTITLED43_CELLAFORMULA_H
#include <iostream>
#include "Observer.h"
#include "Cella.h"
#include "CellaValore.h"
using namespace std;
class CellaFormula : public Cella, public Observer {
public:
    CellaFormula (const string & nomeCella, int dimensione, vector <CellaValore*> &celle) : Cella(nomeCella, dimensione),
                                                                                           celle(celle), valoreCalcolato (0) {
        attach();
    }
    ~CellaFormula() {
        detach();
    }
    void attach () override {
        for (auto c : celle) {
            c->subscribe(this);
        }
    }
    void detach () override {
        for (auto c : celle) {
            c->unsubscribe(this);
        }
    }
    virtual void update () override = 0;
    int getValore () const override {
        return valoreCalcolato;
    }

    void showResult () const {
       cout << "Valore calcolato :" << valoreCalcolato << endl;
    }
protected:
    int valoreCalcolato;
    vector <CellaValore *> &celle;
};

#endif //UNTITLED43_CELLAFORMULA_H
