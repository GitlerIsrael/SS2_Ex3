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
        void reduce();

    public:
        Fraction(int num = 0, int denom = 1);
        int getNum() const{return this->numerator;}
        int getDenom() const{return this->denominator;}
        Fraction operator+(const Fraction& other) const;
        Fraction operator-(const Fraction& other) const;
        Fraction operator*(const Fraction& other) const;
        Fraction operator/(const Fraction& other) const;
        bool operator==(const Fraction& other) const;
        bool operator!=(const Fraction& other) const;
        bool operator>(const Fraction& other) const;
        bool operator<(const Fraction& other) const;
        bool operator>=(const Fraction& other) const;
        bool operator<=(const Fraction& other) const;

        Fraction operator+(float flo) const;
        Fraction operator-(float flo) const;
        Fraction operator*(float flo) const;
        Fraction operator/(float flo) const;
        bool operator==(float flo) const;
        bool operator!=(float flo) const;
        bool operator>(float flo) const;
        bool operator<(float flo) const;
        bool operator>=(float flo) const;
        bool operator<=(float flo) const;


        Fraction& operator++(); //prefix
        Fraction& operator--(); //prefix
        Fraction operator++(int); //postfix
        Fraction operator--(int); //postfix

        friend Fraction operator+(float flo, const Fraction& fraction);
        friend Fraction operator-(float flo, const Fraction& fraction);
        friend Fraction operator*(float flo, const Fraction& fraction);
        friend Fraction operator/(float flo, const Fraction& fraction);
        friend bool operator==(float flo, const Fraction& fraction);
        friend bool operator!=(float flo, const Fraction& fraction);
        friend bool operator>(float flo, const Fraction& fraction);
        friend bool operator<(float flo, const Fraction& fraction);
        friend bool operator>=(float flo, const Fraction& fraction);
        friend bool operator<=(float flo, const Fraction& fraction);


        friend std::ostream& operator<<(std::ostream& output, const Fraction& fraction);
        friend std::istream& operator>>(std::istream& input, Fraction& fraction);
    };

//    Fraction operator+(const float f, const Fraction& fraction);
//    Fraction operator-(const float f, const Fraction& fraction);
//    Fraction operator*(const float f, const Fraction& fraction);
//    Fraction operator/(const float f, const Fraction& fraction);
//    bool operator==(const float f, const Fraction& fraction);
//    bool operator!=(const float f, const Fraction& fraction);
//    bool operator>(const float f, const Fraction& fraction);
//    bool operator<(const float f, const Fraction& fraction);
//    bool operator>=(const float f, const Fraction& fraction);
//    bool operator<=(const float f, const Fraction& fraction);
//
//    std::ostream& operator<<(std::ostream& os, const Fraction& fraction);
//    std::istream& operator>>(std::istream& is, Fraction& fraction);
}