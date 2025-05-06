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
    Cella (const string & n) : nomeCella (n) {} //costruttore cella
   // virtual void show () const {
       // cout<<"Titolo cella: "<<nomeCella<<"e di dimensione"<<dimensione<<endl;
    //}
   virtual void show(int & riga) const {
       mvprintw(riga++, 0, "Titolo cella: %s", nomeCella.c_str());
   }
    const string &getNomeCella() const {
        return nomeCella;
    }

    virtual int getValore () const = 0;
    virtual ~Cella () {}
protected:
    string nomeCella;
};
#endif //UNTITLED43_CELLA_H
