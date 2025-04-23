#include <iostream>
#include <vector>
#include "CellaValore.h"
#include "CellaSomma.h"
#include "CellaMedia.h"
#include "CellaMassimo.h"
#include "CellaMinimo.h"
using namespace std;
int main () {
    CellaValore * a = new CellaValore ("A1", 1,10);
    CellaValore * b = new CellaValore ("B1", 1,20);
    CellaValore * c = new CellaValore ("C1",1,30);

    vector <CellaValore *> celle = {a,b,c};

    CellaSomma * somma = new CellaSomma ("Somma",1,celle);
    cout<<"Stato iniziale :";
    somma->showResult();

    c->setValore(20);

    cout<<"Stato aggiornato: ";
    somma->show();

    CellaMedia * media = new CellaMedia ("Media : ", 1, celle);
    cout<<"Stato inziziale: ";
    media->showResult();

    b->setValore(10);

    cout<<"Stato aggiornato: ";
    media->showResult();

    CellaMassimo * massimo = new CellaMassimo ("Massimo :", 1, celle);
    cout<<"Stato iniziale: ";
    massimo->showResult();

    a->setValore(10);

    cout<<"Stato aggiornato : ";
    massimo->showResult();

    CellaMinimo * minimo = new CellaMinimo ("Minimo : ", 1, celle);
    cout<<"Stato iniziale :";
    minimo ->showResult();

    a->setValore (5);

    cout<<"Stato aggiornato: ";
    minimo->showResult();
}
