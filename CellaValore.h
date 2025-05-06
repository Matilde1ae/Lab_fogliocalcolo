//
// Created by Matilde Giuliani on 23/04/25.
//

#ifndef UNTITLED43_CELLAVALORE_H
#define UNTITLED43_CELLAVALORE_H
#include <iostream>
#include <list>
#include "Cella.h"
#include "Subject.h"
#include <ncurses.h>
using namespace std;
class CellaValore : public Subject, public Cella {
public:
    CellaValore(const string & nomeCella, int v) : Cella (nomeCella), valore (v) {}
    void setValore (int v) {
        valore=v;
        notify ();
    }
    int getValore () const override {
        return valore;
    }
    //void show () const override {
      //  cout<<"Valore :"<<valore<<endl;
        //return valore;
    //}
    void show (int & riga) const override {
        mvprintw(riga ++, 0, "NomeCella: %s, Valore: %d", nomeCella.c_str (), valore);
    }
    void subscribe (Observer * o) override {
        observers.push_back (o);
    }
    void unsubscribe (Observer * o) override {
        observers.remove (o);
    }
    void notify () override {
        for (auto o: observers){
            o->update ();
        }
    }
private:
    int valore;
    list<Observer *> observers;
};
#endif //UNTITLED43_CELLAVALORE_H
