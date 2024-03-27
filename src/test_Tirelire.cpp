//----------------------------------------------------------------------
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN	/*! Use if doctest with its own main function*/
#include "doctest.h"
//----------------------------------------------------------------------


#include <iostream>
#include "Tirelire.hpp"

/**
 * @brief   Test Case #0 : Project structure only
*/
TEST_CASE("testing Tirelire class : Structure only") {
	std::cout << "Structure OK\n"; 
}

/**
 * @brief   Test Case #1 : Tirelire Default Ctor
*/
TEST_CASE("testing Tirelire class : Default Ctor") {
	Tirelire SpiderCochon{};

    bool    Etat = SpiderCochon.estVide();
    CHECK(Etat == true);

    int NbCoins = SpiderCochon.getNbCoins();
    CHECK(NbCoins == 0);
}

TEST_CASE("testing Tirelire class : Add function") {
	Tirelire SpiderCochon{};

    SpiderCochon.Add(Tirelire::Piece::TWENTYCENTS);

    CHECK(SpiderCochon.estVide() == false);

    SpiderCochon.Add(static_cast<Tirelire::Piece>(5));
    CHECK (SpiderCochon.getNbCoins() == 2);

    CHECK_THROWS_WITH(SpiderCochon.Add(static_cast<Tirelire::Piece>(7)), "Coin is not valid");
    CHECK (SpiderCochon.getNbCoins() == 2);

}

TEST_CASE("testing Tirelire class : getTotal function") {
	Tirelire SpiderCochon{};

    CHECK(SpiderCochon.getTotal() == 0);

    SpiderCochon.Add(Tirelire::Piece::TWENTYCENTS);
    SpiderCochon.Add(Tirelire::Piece::ONEEURO);
    SpiderCochon.Add(Tirelire::Piece::TWOCENTS);

    CHECK(SpiderCochon.getTotal() == 122);
}

TEST_CASE("testing Tirelire class : countCoins function") {
    Tirelire SpiderCochon{};
    CHECK(SpiderCochon.countCoins(Tirelire::Piece::ONECENT) == 0);

    SpiderCochon.Add(Tirelire::Piece::ONEEURO);
    CHECK(SpiderCochon.getNbCoins() == 1);
    CHECK(SpiderCochon.countCoins(Tirelire::Piece::ONEEURO) == 1);

    CHECK_THROWS_WITH(unsigned int Nb = SpiderCochon.countCoins(static_cast<Tirelire::Piece>(7)), "Coin is not valid");


}

TEST_CASE("testing Tirelire class : retrieve function") {
    Tirelire SpiderCochon{};

    CHECK_THROWS_WITH(SpiderCochon.retrieve(static_cast<Tirelire::Piece>(7)), "Coin is not valid");
    CHECK_THROWS_WITH(SpiderCochon.retrieve(Tirelire::Piece::ONEEURO), "No corresponding coins inside the vault.");

    SpiderCochon.Add(Tirelire::Piece::ONEEURO);
    SpiderCochon.Add(Tirelire::Piece::ONEEURO);

    CHECK(SpiderCochon.countCoins(Tirelire::Piece::ONEEURO) == 2);
    SpiderCochon.dump();

    SpiderCochon.retrieve(Tirelire::Piece::ONEEURO);
    CHECK(SpiderCochon.countCoins(Tirelire::Piece::ONEEURO) == 1);

}



