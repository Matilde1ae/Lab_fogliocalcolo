//
// Created by Matilde Giuliani on 23/04/25.
//

#ifndef UNTITLED43_CELLA_H
#define UNTITLED43_CELLA_H
#include <iostream>
#include <ncurses.h>
using namespace std;
class Cella {
public:
    Cella (const string & n, int d) : nomeCella (n), dimensione (d) {}
   // virtual void show () const {
       // cout<<"Titolo cella: "<<nomeCella<<"e di dimensione"<<dimensione<<endl;
    //}
   virtual void show(int y) const {
       mvprintw(y, 2, "Titolo cella: %s di dimensione %d", nomeCella.c_str(), dimensione);
   }

    const string &getNomeCella() const {
        return nomeCella;
    }

    virtual int getValore () const = 0;
    virtual ~Cella () {}
protected:
    string nomeCella;
    int dimensione;
};
#endif //UNTITLED43_CELLA_H
