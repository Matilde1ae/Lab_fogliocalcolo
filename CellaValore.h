//
// Created by Matilde Giuliani on 23/04/25.
//

#ifndef UNTITLED43_CELLAVALORE_H
#define UNTITLED43_CELLAVALORE_H
#include <iostream>
#include <list>
#include "Cella.h"
#include "Subject.h"
using namespace std;
class CellaValore : public Subject, public Cella {
public:
    CellaValore(const string & nomeCella, int dimensione, int v) : Cella (nomeCella,dimensione), valore (v) {}
    void setValore (int v) {
        this->valore=v;
        notify ();
    }
    int getValore () const override {
        return valore;
    }
    void show () const override {
        cout<<"Valore :"<<valore<<endl;
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
