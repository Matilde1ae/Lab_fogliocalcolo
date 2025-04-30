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
    Cella (const string & n, int r, int c) : nomeCella (n), riga (r),colonna (c)  {} //inserire colonna e riga
   // virtual void show () const {
       // cout<<"Titolo cella: "<<nomeCella<<"e di dimensione"<<dimensione<<endl;
    //}
   virtual void show(int y) const {
       mvprintw(y, 2, "Titolo cella: %s di dimensione %d", nomeCella.c_str(), riga, colonna);
   }
    const string &getNomeCella() const {
        return nomeCella;
    }

    virtual int getValore () const = 0;
    virtual ~Cella () {}
protected:
    string nomeCella;
    int riga,colonna;
};
#endif //UNTITLED43_CELLA_H
