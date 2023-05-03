//
// Created by israel on 4/28/23.
//
#pragma once
#include <iostream>
using std::istream;
using std::ostream;

namespace ariel{
    class Fraction {
    private:
        int numerator, denominator;

    public:
        void reduce();
        Fraction(int num, int denom);
        Fraction(float flo);
        Fraction();
        int getNumerator() const{return this->numerator;}
        int getDenominator() const{return this->denominator;}
        void setNumerator(int num) {this->numerator=num;}
        void setDenominator(int denom) {this->denominator=denom;}

        Fraction& operator++(); //prefix
        Fraction& operator--(); //prefix
        Fraction operator++(int); //postfix
        Fraction operator--(int); //postfix

        friend void is_overflow(long long numerator, long long denominator);
        friend Fraction operator+(const Fraction& fraction_1, const Fraction& fraction_2);
        friend Fraction operator-(const Fraction& fraction_1, const Fraction& fraction_2);
        friend Fraction operator*(const Fraction& fraction_1, const Fraction& fraction_2);
        friend Fraction operator/(const Fraction& fraction_1, const Fraction& fraction_2);
        friend bool operator==(const Fraction& fraction_1, const Fraction& fraction_2);
        friend bool operator>(const Fraction& fraction_1, const Fraction& fraction_2);
        friend bool operator<(const Fraction& fraction_1, const Fraction& fraction_2);
        friend bool operator>=(const Fraction& fraction_1, const Fraction& fraction_2);
        friend bool operator<=(const Fraction& fraction_1, const Fraction& fraction_2);


        friend std::ostream& operator<<(std::ostream& output, const Fraction& fraction);
        friend std::istream& operator>>(std::istream& input, Fraction& fraction);

//        Fraction operator+(const Fraction& other);
//        Fraction operator-(const Fraction& other);
//        Fraction operator*(const Fraction& other);
//        Fraction operator/(const Fraction& other);
//        bool operator==(const Fraction& other) const;
//        bool operator!=(const Fraction& other) const;
//        bool operator>(const Fraction& other) const;
//        bool operator<(const Fraction& other) const;
//        bool operator>=(const Fraction& other) const;
//        bool operator<=(const Fraction& other) const;
//
//        Fraction operator+(float flo) const;
//        Fraction operator-(float flo) const;
//        Fraction operator*(float flo) const;
//        Fraction operator/(float flo) const;
//        bool operator==(float flo) const;
//        bool operator!=(float flo) const;
//        bool operator>(float flo) const;
//        bool operator<(float flo) const;
//        bool operator>=(float flo) const;
//        bool operator<=(float flo) const;
//
//
//        Fraction& operator++(); //prefix
//        Fraction& operator--(); //prefix
//        Fraction operator++(int); //postfix
//        Fraction operator--(int); //postfix
//
//        friend Fraction operator+(float flo, const Fraction& fraction);
//        friend Fraction operator-(float flo, const Fraction& fraction);
//        friend Fraction operator*(float flo, const Fraction& fraction);
//        friend Fraction operator/(float flo, const Fraction& fraction);
//        friend bool operator==(float flo, const Fraction& fraction);
//        friend bool operator!=(float flo, const Fraction& fraction);
//        friend bool operator>(float flo, const Fraction& fraction);
//        friend bool operator<(float flo, const Fraction& fraction);
//        friend bool operator>=(float flo, const Fraction& fraction);
//        friend bool operator<=(float flo, const Fraction& fraction);
//
//
//        friend std::ostream& operator<<(std::ostream& output, const Fraction& fraction);
//        friend std::istream& operator>>(std::istream& input, Fraction& fraction);
    };
}