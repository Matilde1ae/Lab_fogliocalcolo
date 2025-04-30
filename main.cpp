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
void stampaStato(vector<CellaValore*>& celle, CellaSomma* somma, CellaMedia* media, CellaMassimo* massimo, CellaMinimo* minimo) {
    clear();
    int riga = 2;
    for (auto c: celle) {
        c->show(riga++);
    }
    riga++;
    somma->showResult(riga++);
    media->showResult(riga++);
    massimo->showResult(riga++);
    minimo->showResult(riga++);
    mvprintw(riga + 2, 2, "Premi un tasto per continuare...");
    refresh();
    getch();
}

int main () {
    initscr();
    cbreak();
    noecho();
    curs_set(FALSE);

    CellaValore *a = new CellaValore("A", 1, 10);
    CellaValore *b = new CellaValore("B", 1, 20);
    CellaValore *c = new CellaValore("C", 1, 30);
    vector<CellaValore *> celle = {a, b, c};

   CellaSomma * somma;
   /*
    CellaMedia * media = new CellaMedia("Media", 1, celle);
    CellaMassimo * massimo = new CellaMassimo("Massimo", 1, celle);
    CellaMinimo * minimo = new CellaMinimo("Minimo", 1, celle);
*/
    FoglioCalcolo * f;
    f-> addCelleValore (a);
    f-> addCelleValore(b);
    f-> addCelleValore(c);
    somma = f->getSomma();

    stampaStato(celle, somma, media, massimo, minimo);

    b->setValore(10);
    stampaStato(celle, somma, media, massimo, minimo);

    a->setValore(5);
    stampaStato(celle, somma, media, massimo, minimo);


    getch();
    endwin();

    delete a;
    delete b;
    delete c;
    delete somma;
    delete media;
    delete massimo;
    delete minimo;
    return 0;
}


