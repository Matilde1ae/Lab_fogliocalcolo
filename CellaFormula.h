//
// Created by Matilde Giuliani on 23/04/25.
//

#ifndef UNTITLED43_CELLAFORMULA_H
#define UNTITLED43_CELLAFORMULA_H
#include <iostream>
#include "Observer.h"
#include "Cella.h"
#include "CellaValore.h"
#include <ncurses.h>
using namespace std;
class CellaFormula : public Cella, public Observer {
public:
    CellaFormula (const string & nomeCella, int riga, int colonna) : Cella(nomeCella, riga, colonna),
                                                                                           celle(celle), valoreCalcolato (0) {
        attach();
    }
    ~CellaFormula() {
        detach();
    }
    //metodi per aggiungere e togliere le celle,togliere dimensione
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

    //void showResult () const {
    //   cout << "Valore calcolato :" << valoreCalcolato << endl;
    //}
    void showResult(int y) const {
        mvprintw(y, 2, "Valore calcolato %s: %d", nomeCella.c_str(), valoreCalcolato);
    }
    void setValoreCalcolato (int valore) {
        valoreCalcolato=valore;
    }

protected:
    int valoreCalcolato;
    vector <CellaValore *> &celle;
};

#endif //UNTITLED43_CELLAFORMULA_H
