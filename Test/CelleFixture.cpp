//
// Created by Matilde Giuliani on 23/04/25.
//
#include <gtest/gtest.h>
#include "../CellaMassimo.h"
#include "../CellaMedia.h"
#include "../CellaMinimo.h"
#include "../CellaSomma.h"
#include "../FoglioCalcolo.h"

class CelleFixture : public ::testing ::Test {
protected:
    void SetUp() override {
        a = new CellaValore("A1", 10);
        b = new CellaValore("B1", 20);
        c = new CellaValore("C1", 30);
        celle = {a, b, c};
    }

    void TearDown() override {
        delete a;
        delete b;
        delete c;
    }

    CellaValore *a;
    CellaValore *b;
    CellaValore *c;
    vector<CellaValore *> celle;
};

TEST_F(CelleFixture, TestMassimo) {
    CellaMassimo massimo("Massimo");
    a->setValore(15);
    b->setValore(20);
    c->setValore(25);
    massimo.calcola(celle);
    EXPECT_EQ(massimo.getValore(), 25);
}

TEST_F(CelleFixture, TestMedia) {
    CellaMedia media("Media");
    a->setValore(10);
    b->setValore(15);
    c->setValore(20);
    media.calcola(celle);
    EXPECT_EQ(media.getValore(), 15);
}

TEST_F(CelleFixture, TestMinimo) {
    CellaMinimo minimo("Minimo");
    a->setValore(20);
    b->setValore(25);
    c->setValore(30);
    minimo.calcola(celle);
    EXPECT_EQ(minimo.getValore(), 20);
}

TEST_F(CelleFixture, TestSomma) {
    CellaSomma somma("Somma");
    a->setValore(5);
    b->setValore(10);
    c->setValore(15);
    somma.calcola(celle);
    EXPECT_EQ(somma.getValore(), 30);
}
TEST_F(CelleFixture, TestFoglioCalcolo) {
    FoglioCalcolo foglio("Foglio");

    foglio.addCellaValore(a);
    foglio.addCellaValore(b);
    foglio.addCellaValore(c);
    foglio.attach();
    foglio.update();

    EXPECT_EQ(foglio.getSomma()->getValore(), 60);
    EXPECT_EQ(foglio.getMedia()->getValore(), 20);
    EXPECT_EQ(foglio.getMassimo()->getValore(), 30);
    EXPECT_EQ(foglio.getMinimo()->getValore(), 10);

    b->setValore(5);
    foglio.update();

    EXPECT_EQ(foglio.getSomma()->getValore(), 45);
    EXPECT_EQ(foglio.getMedia()->getValore(), 15);
    EXPECT_EQ(foglio.getMassimo()->getValore(), 30);
    EXPECT_EQ(foglio.getMinimo()->getValore(), 5);
}