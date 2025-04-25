//
// Created by Matilde Giuliani on 23/04/25.
//
#include <gtest/gtest.h>
#include "../CellaMassimo.h"
#include "../CellaMedia.h"
#include "../CellaMinimo.h"
#include "../CellaSomma.h"

class CelleFixture : public ::testing ::Test {
protected:
    void setup (){
        CellaValore * a = new CellaValore("A1", 1,10);
        CellaValore * b = new CellaValore ("B1", 1, 20);
        CellaValore * c = new CellaValore ("C1", 1,30);
        vector <CellaValore *> celle = {a,b,c};
    }
    void TearDown () {
        delete a;
        delete b;
        delete c;
    }
    CellaValore * a = new CellaValore("A1", 1,10);
    CellaValore * b = new CellaValore ("B1", 1, 20);
    CellaValore * c = new CellaValore ("C1", 1,30);
    vector <CellaValore *> celle = {a,b,c};
};
TEST_F(CelleFixture, TestMassimo) {
    CellaMassimo massimo("Massimo :", 1, celle);
    a->setValore(15);
    b->setValore(20);
    c->setValore(25);
    EXPECT_EQ (massimo.getValore(), 25);
}

TEST_F(CelleFixture, TestMedia) {
    CellaMedia media("Media :", 1, celle);
    a->setValore(10);
    b->setValore(15);
    c->setValore(20);
    EXPECT_EQ (media.getValore(), 15);
}
TEST_F(CelleFixture, TestMinimo){
    CellaMinimo minimo ("Minimo :", 1, celle);
    a->setValore (20);
    b->setValore (25);
    c->setValore (30);
    EXPECT_EQ (minimo.getValore(),20 );
}
TEST_F(CelleFixture, TestSomma){
    CellaSomma somma ("Somma :", 1, celle);
    a->setValore (5);
    b->setValore (10);
    c->setValore (15);
    EXPECT_EQ (somma.getValore(),30);
}