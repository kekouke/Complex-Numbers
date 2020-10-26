#include <iostream>
#include <sstream>
#include "rational.h"
#include "complex_num.h"
#include "big_integers.h"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

using namespace std;

TEST_CASE("Class Rational testing", "[Rational]") {
    {
        const Rational r1(3, 10);
        REQUIRE((r1.getNumerator() == 3 && r1.getDenominator() == 10));
    }
    {
        const Rational r1(8, 12);
        REQUIRE((r1.getNumerator() == 2 && r1.getDenominator() == 3));
    } 
    {
        const Rational r1(-4, 6);
        REQUIRE((r1.getNumerator() == -2 && r1.getDenominator() == 3));
    } 
    {
        const Rational r1(4, -6);
        REQUIRE((r1.getNumerator() == -2 && r1.getDenominator() == 3));
    }
    {
        const Rational r1(0, 15);
        REQUIRE((r1.getNumerator() == 0 && r1.getDenominator() == 1));
    }
    {
        const Rational defaultConstructed;
        REQUIRE((defaultConstructed.getNumerator() == 0 && defaultConstructed.getDenominator() == 1));
    }

    SECTION("Algebraic operations with rational numbers") {
        {
            Rational a(2, 3);
            Rational b(2, 3);
            REQUIRE(a == b);
        }
        {
            Rational a(4, 6);
            Rational b(2, 3);
            REQUIRE(a == b);
        }
        {
            Rational a(2, -3);
            Rational b(-2, 3);
            REQUIRE(a == b);
        }
        {
            Rational a;
            Rational b(0, 15);
            REQUIRE(a == b);
        }
        {
            Rational a(2, 3);
            Rational b(4, 3);
            REQUIRE(a + b == Rational(2, 1));
        }
        {
            Rational a(-4, 3);
            Rational b(2, 3);
            REQUIRE(a + b == Rational(-2, 3));
        }
        {
            Rational a(15, 100);
            Rational b(-15, 100);
            REQUIRE(a + b == Rational(0, 1));
        }
        {
            Rational a(5, 7);
            Rational b(2, 9);
            REQUIRE(a - b == Rational(31, 63));
        }
        {
            Rational a(582, 1000);
            Rational b(999, 1000);
            REQUIRE(a - b == Rational(-417, 1000));
        }
        {
            Rational a(1, 1);
            REQUIRE(a - a == Rational(0, 1));
        }
        {
            Rational a(7, 8);
            REQUIRE(-a == Rational(-7, 8));
        }
        {
            Rational a(-7, 8);
            REQUIRE(-a == Rational(7, 8));
        }
        {
            Rational a(2, 3);
            Rational b(4, 3);
            REQUIRE(a * b == Rational(8, 9));
        }
        {
            Rational a(-1234567, 7654321);
            Rational b(-789, 987);
            REQUIRE(a * b == Rational(974073363, 7554814827));
        }
        {
            Rational a(-1234567, 7654321);
            Rational b(789, 987);
            REQUIRE(a * b == Rational(-974073363, 7554814827));
        }
        {
            Rational a(5, 4);
            Rational b(15, 8);
            REQUIRE(a / b == Rational(2, 3));
        }
        {
            Rational a(-1234567, 7654321);
            Rational b(-789, 987);
            REQUIRE(a / b == Rational(406172543, 2013086423));
        }
        {
            Rational a(-1234567, 7654321);
            Rational b(789, 987);
            REQUIRE(a / b == Rational(-406172543, 2013086423));
        }
        {
            Rational a;
            Rational b(15, 8);
            REQUIRE(a / b == Rational());
        }
    }

    SECTION("Input operation") {
        stringstream stream;
        std::string str;
        stream << Rational(15, 18) << " " << Rational(-7, 9);
        getline(stream, str);
        REQUIRE("5/6 -7/9" == str);
    }

    SECTION("Functions") {
        {
            Rational a(2, 5);
            REQUIRE(0.4 == a.toDouble());
        }
        {
            Rational a(-9, 100);
            REQUIRE(-0.09 == a.toDouble());
        }
        {
            Rational a;
            REQUIRE(0 == a.toDouble());
        }
        {
            Rational a(2, 3);
            REQUIRE(Approx(0.666667).epsilon(0.01) == a.toDouble());
        }
        {
            Rational a(6723472, 781236821349);
            REQUIRE(Approx(8.60619e-06).epsilon(0.01) == a.toDouble());
        }
    }
}
