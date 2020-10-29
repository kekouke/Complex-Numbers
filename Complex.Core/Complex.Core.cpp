#include <iostream>
#include <sstream>
#include "rational.h"
#include "complex_num.h"

#define CATCH_CONFIG_MAIN
#include "../catch.hpp"

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
        const Rational r1(5);
        REQUIRE((r1.getNumerator() == 5 && r1.getDenominator() == 1));
    }
    {
        const Rational r1(-5);
        REQUIRE((r1.getNumerator() == -5 && r1.getDenominator() == 1));
    }
    {
        const Rational r1(56346346436436);
        REQUIRE((r1.getNumerator() == 56346346436436 && r1.getDenominator() == 1));
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
            REQUIRE(a + b == Rational(2));
        }
        {
            Rational a(-4, 3);
            Rational b(2, 3);
            REQUIRE(a + b == Rational(-2, 3));
        }
        {
            Rational a(15, 100);
            Rational b(-15, 100);
            REQUIRE(a + b == Rational());
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
            REQUIRE(a - a == Rational());
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

TEST_CASE("Class Complex testing", "[Complex]") {
    {
        const Complex c1({ 5, 4 }, { 15, 8 });
        REQUIRE((c1.getReal() == Rational(5, 4) && c1.getImaginary() == Rational(15, 8)));
    }
    {
        const Complex c1({ -5, 4 }, { -15, 8 });
        REQUIRE((c1.getReal() == Rational(-5, 4) && c1.getImaginary() == Rational(-15, 8)));
    }
    {
        const Complex c1(1);
        REQUIRE((c1.getReal() == Rational(1, 1) && c1.getImaginary() == Rational(0, 1)));
    }
    {
        const Complex c1(12345678903);
        REQUIRE((c1.getReal() == Rational(12345678903) && c1.getImaginary() == Rational(0, 1)));
    }
    {
        const Complex c1;
        REQUIRE((c1.getReal() == Rational() && c1.getImaginary() == Rational()));
    }
    {
        const Complex c1(40.01);
        REQUIRE((c1.getReal() == Rational(4001, 100) && c1.getImaginary() == Rational()));
    }
    {
        const Complex c1(40.01, -12.9);
        REQUIRE((c1.getReal() == Rational(4001, 100) && c1.getImaginary() == Rational(-129, 10)));
    }
    {
        const Complex c1(0.12345678);
        REQUIRE(c1.getReal() == Rational(12345678, 100'000'000));
    }

    SECTION("Algebraic operations with complex numbers") {
        {
            Complex a({ 2, 3 }, { -5 });
            Complex b({ 2, 3 }, { -5 });
            REQUIRE(a == b);
        }
        {
            Complex a({ 4, 6 }, { -5 });
            Complex b({ 2, 3 }, { -10, 2 });
            REQUIRE(a == b);
        }
        {
            Complex a(9, 0);
            Complex b(9, 3);
            REQUIRE(a != b);
        }
        {
            Complex a({ 2, 3 }, { -5 });
            Complex b({ 2, 3 }, { -5, 1 });
            REQUIRE(a + b == Complex({ 4, 3 }, { -10 }));
        }
        {
            Complex a({ 5, 1 });
            REQUIRE(a + 5 == Complex({ 10, 1 }));
        }
        {
            Complex a({ 7, 3 }, { 8, 9 });
            REQUIRE(a + 5 == Complex({ 22, 3 }, { 8, 9 }));
        }
        {
            Complex a(5555555);

            REQUIRE(a + 5 == Complex(5555560));
        }
        {
            Complex a(1);
            REQUIRE(a + 0.1 == Complex(1.1));
        }
        {
            Complex a(1.1, 4.3);
            Complex b(-1.1, 4.3);
            REQUIRE(a + b == Complex(0.0, 8.6));
        }
        {
            Complex a({ 2, 3 }, { -5 });
            Complex b({ 2, 3 }, { -5 });
            REQUIRE(a - b == Complex());
        }
        {
            Complex a({ 2, 3 }, { -5, 1 });
            Complex b({ 2, 3 }, { -6, 1 });
            REQUIRE(a - b == Complex({ 0, 1 }, { 1, 1 }));
        }
        {
            Complex a(Rational{ 5, 1 });
            REQUIRE(a - 5 == Complex());
        }
        {
            Complex a({ 7, 3 }, { 8, 9 });
            REQUIRE(a - 5 == Complex({ -8, 3 }, { 8, 9 }));
        }
        {
            Complex a(40.001, 12.9);
            REQUIRE(a - Complex(40) == Complex(0.001, 12.9));
        }
        {
            Complex a(5555555);
            REQUIRE(a - 111 == 5555444);
        }
        {
            Complex a(1);
            REQUIRE(a - 0.75 == Complex(0.25));
        }
        {
            Complex a({ 2, 3 }, { -5, 1 });
            Complex b({ 2, 3 }, { -5, 1 });
            REQUIRE(a * b == Complex({ -221, 9 }, { -20, 3 }));
        }
        {
            Complex a(0.1);
            Complex b(10);
            REQUIRE(a * b == 1);
        }
        {
            Complex a(0, 0);
            Complex b(0, 0);
            REQUIRE(a * b == 0);
        }
        {
            REQUIRE(Complex(Rational{ 2, 3 }) * Complex(3) == Complex(Rational{ 2, 1 }));
        }
        {
            Complex a({ 2, 3 }, { -5, 1 });
            Complex b({ 2, 3 }, { -5, 1 });
            REQUIRE(a / b == Complex({ 1 }));
        }
        {
            Complex a(0.1);
            Complex b(1.1);
            REQUIRE((a / b).getReal().toDouble() == Approx(0.09090).epsilon(0.01));
        }
        {
            Complex a({ 2, 3 }, { -5, 1 });
            Complex b({ 2, 3 }, { -5, 1 });
            REQUIRE((a += b) == Complex({ 4, 3 }, { -10, 1 }));
        }
        {
            Complex a({ 2, 3 }, { -5, 1 });
            Complex b({ 2, 3 }, { -5, 1 });
            REQUIRE((a -= b) == Complex({ 0 }));
        }
        {
            Complex a({ 2, 3 }, { -5, 1 });
            Complex b({ 2, 3 }, { -5, 1 });
            REQUIRE((a *= b) == Complex({ -221, 9 }, { -20, 3 }));
        }
        {
            Complex a({ 2, 3 }, { -5, 1 });
            Complex b({ 2, 3 }, { -5, 1 });
            REQUIRE((a /= b) == Complex({ 1 }));
        }
    }

    SECTION("Input operation") {
        {
            stringstream stream;
            std::string str;
            stream << Complex({ 2, 3 }, { -5,1 }) << " ; " << Complex(Rational{ -13, 8 });
            getline(stream, str);
            REQUIRE("2/3 + -5/1i ; -13/8" == str);
        }
        {
            stringstream stream;
            std::string str;
            stream << Complex(5);
            getline(stream, str);
            REQUIRE("5/1" == str);
        }
    }

    SECTION("Functions") {
        {
            Complex c1;
            c1.setReal({ 2, 3 });
            c1.setImaginary({ -5, 1 });
            REQUIRE(c1 == Complex({ 2, 3 }, { -5, 1 }));
        }
        {
            Complex c1({ 1, 1 }, { 2, 1 });
            REQUIRE(c1.pow(2) == Complex({ -3, 1 }, { 4, 1 }));
        }
        {
            Complex c1({ -55,10 }, { -66,10 });
            REQUIRE(Approx(8.5912).epsilon(0.01) == c1.abs());
        }
        {
            Complex c1({ 55,10 }, { 66,10 });
            REQUIRE(Approx(0.876058050598).epsilon(0.01) == c1.arg());
        }
    }
}