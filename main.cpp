#include <iostream>
#include <vector>
#include <algorithm>
#include "CellaValore.h"
#include "CellaSomma.h"
#include "CellaMassimo.h"
#include "CellaMinimo.h"
#include "CellaMedia.h"
#include <ncurses.h>
using namespace std;
/*void printCelle (WINDOW * win,
                 vector <CellaValore *> & celle,
                 CellaFormula * somma,
                 CellaFormula * massimo,
                 CellaFormula * minimo,
                 CellaFormula * media);
void printCelle (WINDOW * win,
vector <CellaValore *> & celle,
CellaFormula * somma,
CellaFormula * massimo,
CellaFormula * minimo,
CellaFormula * media)
{
   werase(win);
    box(win,0,0);
    int y=1;
    for (auto * c : celle){
        mvwprintw(win, y++, 2, "%s=%d",c->getNomeCella().c_str(), c->getValore());
    }
    y++;
    mvwprintw(win, y++,2,"Somma = %d", somma->getValore());
    mvwprintw(win, y++,2,"Massimo = %d", massimo->getValore());
    mvwprintw(win, y++,2,"Minimo = %d", minimo->getValore());
    mvwprintw(win, y++,2,"Media = %d", media->getValore());
    wrefresh(win);
}
              vector<CellaValore *> &celle,
                CellaFormula *somma,
                CellaFormula *massimo,
                CellaFormula *minimo,
                CellaFormula *media) {
    werase(win);
    box(win, 0, 0);
    int y = 1;
    for (auto *c : celle) {
        mvwprintw(win, y++, 2, "%s = %d", c->getNomeCella().c_str(), c->getValore());
    }
    y++;
    mvwprintw(win, y++, 2, "Somma   = %d", somma->getValore());
    mvwprintw(win, y++, 2, "Massimo = %d", massimo->getValore());
    mvwprintw(win, y++, 2, "Minimo  = %d", minimo->getValore());
    mvwprintw(win, y++, 2, "Media   = %d", media->getValore());
    wrefresh(win);
}*/

int main () {
    initscr();
    cbreak();
    noecho();
    curs_set(FALSE);
    CellaValore * a = new CellaValore ("A1", 1,10);
    CellaValore * b = new CellaValore ("B1", 1,20);
    CellaValore * c = new CellaValore ("C1",1,30);

    vector<CellaValore*> celle;
    celle.push_back(a);
    celle.push_back(b);
    celle.push_back(c);

    CellaSomma * somma = new CellaSomma ("Somma",1,celle);
    CellaMedia * media = new CellaMedia ("Media : ", 1, celle);
    CellaMassimo * massimo = new CellaMassimo ("Massimo :", 1, celle);
    CellaMinimo * minimo = new CellaMinimo ("Minimo : ", 1, celle);

    mvprintw(2, 2, "B1: %d", b->getValore());
    mvprintw(3, 2, "C1: %d", c->getValore());
    mvprintw(4, 2, "Somma: %d", somma->getValore());
    mvprintw(5, 2, "Media: %d", media->getValore());
    mvprintw(6, 2, "Massimo: %d", massimo->getValore());
    mvprintw(7, 2, "Minimo: %d", minimo->getValore());
    refresh();

    getch();
    endwin();
    return 0;
}
    /*initscr();
    noecho ();
    curs_set(FALSE);
    CellaValore * a = new CellaValore ("A1", 1,10);
    CellaValore * b = new CellaValore ("B1", 1,20);
    CellaValore * c = new CellaValore ("C1",1,30);

    //vector <CellaValore *> celle = {a,b,c};
    vector<CellaValore*> celle;
    celle.push_back(a);
    celle.push_back(b);
    celle.push_back(c);

    CellaSomma * somma = new CellaSomma ("Somma",1,celle);
    CellaMedia * media = new CellaMedia ("Media : ", 1, celle);
    CellaMassimo * massimo = new CellaMassimo ("Massimo :", 1, celle);
    CellaMinimo * minimo = new CellaMinimo ("Minimo : ", 1, celle);
    printw("=== Stato iniziale ===\n");
    somma->showResult();
    media->showResult();
    massimo->showResult();
    minimo->showResult();

    // Modifiche
    printw("\n=== Dopo modifica valori ===\n");
    c->setValore(20);
    b->setValore(10);
    a->setValore(5);

    somma->showResult();
    media->showResult();
    massimo->showResult();
    minimo->showResult();

    refresh();

   cout<<"Stato iniziale :";
    somma->showResult();

    c->setValore(20);

    cout<<"Stato aggiornato: ";
    somma->show();

    cout<<"Stato inziziale: ";
    media->showResult();

    b->setValore(10);

    cout<<"Stato aggiornato: ";
    media->showResult();


    cout<<"Stato iniziale: ";
    massimo->showResult();

    a->setValore(10);

    cout<<"Stato aggiornato : ";
    massimo->showResult();
    printw("Stato iniziale:\n");
    refresh();
    minimo ->showResult();

    a->setValore (5);

    cout<<"Stato aggiornato: ";
    minimo->showResult();

    getch ();
    endwin ();
    return 0;*/
    /*initscr();
    noecho();
    curs_set(FALSE);

    CellaValore *a = new CellaValore("A1", 1, 10);
    CellaValore *b = new CellaValore("B1", 1, 20);
    CellaValore *c = new CellaValore("C1", 1, 30);

    vector<CellaValore*> celle;
    celle.push_back(a);
    celle.push_back(b);
    celle.push_back(c);

    CellaSomma *somma = new CellaSomma("Somma", 1, celle);
    CellaMedia *media = new CellaMedia("Media", 1, celle);
    CellaMassimo *massimo = new CellaMassimo("Massimo", 1, celle);
    CellaMinimo *minimo = new CellaMinimo("Minimo", 1, celle);



    endwin();
    return 0;


   initscr();
    noecho();
    curs_set(FALSE);
    refresh();

    //WINDOW *wins = newwin(20, 40, 1, 1);

    CellaValore *a = new CellaValore("A", 1, 10);
    CellaValore *b = new CellaValore("B", 1, 20);
    CellaValore *c = new CellaValore("C", 1, 30);
    //CellaValore a("A",1,10), b("B",1,15),c("C",1,20);
    vector <CellaValore *> celle = {a,b,c};
    //vector<CellaValore *> celle;
    //celle.push_back(a);
    //celle.push_back(b);
    //celle.push_back(c);

    //CellaSomma somma1("Somma1",1,celle);
    //CellaMassimo massimo1("Massimo1",1,celle);
    //CellaMinimo minimo1 ("Minimo1",1,celle);
    //CellaMedia media1 ("Media1",1,celle);
    //CellaFormula *somma1 = new CellaSomma("Somma", 1, celle);
    //CellaFormula *massimo1 = new CellaMassimo("Massimo", 1, celle);
    //CellaFormula *minimo1 = new CellaMinimo("Minimo", 1, celle);
    //CellaFormula *media1 = new CellaMedia("Media", 1, celle);

    //printCelle(wins, celle, somma1, massimo1, minimo1, media1);
    //c->setValore(5);
    //printCelle(wins, celle, somma1, massimo1, minimo1, media1);

    CellaSomma * somma = new CellaSomma ("Somma",1,celle);
    cout<<"Stato iniziale :";
    somma->showResult();

    cout<<"Stato aggiornato: ";
    somma->show();

    CellaMedia * media = new CellaMedia ("Media : ", 1, celle);
    cout<<"Stato inziziale: ";
    media->showResult();

    //b->setValore(10);

    cout<<"Stato aggiornato: ";
    media->showResult();

    CellaMassimo * massimo = new CellaMassimo ("Massimo :", 1, celle);
    cout<<"Stato iniziale: ";
    massimo->showResult();

    //a->setValore(10);

    //cout<<"Stato aggiornato : ";
    //massimo->showResult();

    CellaMinimo * minimo = new CellaMinimo ("Minimo : ", 1, celle);
    cout<<"Stato iniziale :";
    minimo ->showResult();

    //a->setValore (5);

    //cout<<"Stato aggiornato: ";
    //minimo->showResult();
    getch();
    endwin();
    return 0;
}*/