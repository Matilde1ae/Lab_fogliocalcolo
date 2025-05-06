#include <iostream>
#include <vector>
#include <algorithm>
#include "CellaValore.h"
#include "CellaSomma.h"
#include "CellaMassimo.h"
#include "CellaMinimo.h"
#include "CellaMedia.h"
#include "FoglioCalcolo.h"
#include <ncurses.h>
using namespace std;
void stampaStato( vector<CellaValore*>& celle,CellaSomma* somma, CellaMedia* media, CellaMassimo* massimo,
                  CellaMinimo* minimo, int & riga) {
    clear ();
    riga =0;
    mvprintw(riga++,0,"Stato inziale:");

    for (auto c : celle) {
        c->show(riga);
    }
    riga++;
    somma->showResult(riga);
    media->showResult(riga);
    massimo->showResult(riga);
    minimo->showResult(riga);
    mvprintw(riga ++,0, "Premi invio per continuare...");
    refresh ();
    getch();
}
int main () {
    initscr();
    cbreak();
    noecho();
    curs_set(FALSE);

    int riga =0;
    CellaValore *a = new CellaValore("A", 10);
    CellaValore *b = new CellaValore("B",20);
    CellaValore *c = new CellaValore("C", 30);
    vector < CellaValore * > celle = {a, b, c};

    FoglioCalcolo * f = new FoglioCalcolo("Foglio");

    f->addCellaValore(a);
    f->addCellaValore(b);
    f->addCellaValore(c);
    f->attach ();

    stampaStato(celle, f->getSomma(), f->getMedia(),f->getMassimo (),f->getMinimo(), riga);
    f->update ();
    stampaStato(celle, f->getSomma(), f->getMedia(),f->getMassimo (),f->getMinimo(), riga);


    b->setValore(10);
    f->update ();
    stampaStato(celle, f->getSomma(), f->getMedia(),f->getMassimo (),f->getMinimo(),riga);

    a->setValore(5);
    f->update();
    stampaStato(celle, f->getSomma(), f->getMedia(),f->getMassimo (),f->getMinimo(),riga);

    getch();
    endwin();

    delete f;
    delete a;
    delete b;
    delete c;

    return 0;
};


