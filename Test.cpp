//
// Created by israel on 4/28/23.
//

#include "doctest.h"
#include "sources/Fraction.hpp"
#include <iostream>

using namespace ariel;
using namespace std;

TEST_CASE("Check constructors") {
    CHECK_NOTHROW(Fraction(3, 4)); // OK.
    CHECK_THROWS(Fraction(1, 0)); //can't build a fraction withe zero denominator.
}

TEST_CASE("Test Fraction class operators") {
    // Initialize Fractions:
    Fraction f(1,1);
    Fraction f1(2, 4);
    Fraction f2(1, 2);

    SUBCASE("Test Fraction addition") {
        Fraction result = f1 + f2;
        CHECK((result.getNum() == 1));
        CHECK((result.getDenom() == 1));

        result = f1 + 0.5;
        CHECK((result.getNum() == 1));
        CHECK((result.getDenom() == 1));

        f++;
        CHECK((f.getNum() == 2 && f.getDenom() == 2));
        ++f;
        CHECK((f.getNum() == 3 && f.getDenom() == 3));
    }

    SUBCASE("Test Fraction subtraction and Zero fraction") {
        Fraction result = f1 - f2;
        CHECK((result.getNum() == 0));
        CHECK((result.getDenom() == 1));

        result = f1 - 0.5;
        CHECK((result.getNum() == 0));
        CHECK((result.getDenom() == 1));

        f--;
        CHECK((f.getNum() == 2 && f.getDenom() == 2));
        --f;
        CHECK((f.getNum() == 1 && f.getDenom() == 1));
    }

    SUBCASE("Test Fraction multiplication") {
        Fraction result = f1 * f2;
        CHECK((result.getNum() == 1));
        CHECK((result.getDenom() == 4));

        result = f1 * 0.5;
        CHECK((result.getNum() == 1));
        CHECK((result.getDenom() == 4));
    }

    SUBCASE("Test Fraction division") {
        Fraction result = f1 / f2;
        CHECK((result.getNum() == 1));
        CHECK((result.getDenom() == 1));

        result = f1 / 0.5;
        CHECK((result.getNum() == 1));
        CHECK((result.getDenom() == 1));
    }

    SUBCASE("Test division in Zero throws exception") {
        CHECK_THROWS(f1 / 0);
        CHECK_THROWS(f1 / Fraction(0,1));
        CHECK_THROWS(0.5 / Fraction(0,1));
    }

    SUBCASE("Test Fraction equality and inequality") {
        Fraction f3(3, 4);

        CHECK((f1 == f2));
        CHECK((f1 != f3));
        CHECK((f3 > f1));
        CHECK((f3 >= f1));
        CHECK((f2 >= f1));
    }

    SUBCASE("Test Fraction simplification") {
        Fraction f4(10, 20);
        Fraction f5(6, 9);

        CHECK((f4.getNum() == 1));
        CHECK((f4.getDenom() == 2));
        CHECK((f4 == 0.5));
        CHECK((0.5 == f4));

        CHECK((f5.getNum() == 2));
        CHECK((f5.getDenom() == 3));
        CHECK((f5 == 0.666));
        CHECK((0.666 == f5));
    }
}