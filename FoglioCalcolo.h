//
// Created by Matilde Giuliani on 30/04/25.
//

#ifndef UNTITLED43_FOGLIOCALCOLO_H
#define UNTITLED43_FOGLIOCALCOLO_H
#include <iostream>
#include "CellaValore.h"
#include "Observer.h"
#include "CellaSomma.h"
#include "CellaMassimo.h"
#include "CellaMinimo.h"
#include "CellaMedia.h"
using namespace std;
class FoglioCalcolo : public Observer {  // TODO aggiungere test
public:
    FoglioCalcolo (const string & n) : nomeFoglio (n) {
        somma = new CellaSomma ("Somma");
        media = new CellaMedia ("Media");
        minimo = new CellaMinimo ("Minimo");
        massimo = new CellaMassimo ("Massimo");
    }
    ~FoglioCalcolo(){
        detach();
        delete somma;
        delete media;
        delete massimo;
        delete minimo;
    }
    void attach () override {
        for (auto cella : celleSelezionate) {
            cella->subscribe(this);
        }
    }
    void detach () override {
        for (auto cella : celleSelezionate) {
            cella->unsubscribe(this);
        }
    }
    void addCellaValore (CellaValore * cella) {
        celleSelezionate.push_back(cella);
    }
    void removeCellaValore (CellaValore * cella) {
        auto it = find (celleSelezionate.begin (), celleSelezionate.end (), cella);
        if (it != celleSelezionate.end()){
            celleSelezionate.erase(it);
        }
    }
    void update () override {
        somma->calcola(celleSelezionate);
        media->calcola (celleSelezionate);
        minimo->calcola (celleSelezionate);
        massimo->calcola (celleSelezionate);
    }
    CellaSomma * getSomma () {
        return somma;
    }
    CellaMedia * getMedia () {
        return media;
    }
    CellaMinimo * getMinimo () {
        return minimo;
    }
    CellaMassimo * getMassimo () {
        return massimo;
    }
private:
    string nomeFoglio;
    vector <CellaValore *> celleSelezionate;
    CellaSomma * somma;
    CellaMassimo * massimo;
    CellaMinimo * minimo;
    CellaMedia * media;
};
#endif //UNTITLED43_FOGLIOCALCOLO_H
