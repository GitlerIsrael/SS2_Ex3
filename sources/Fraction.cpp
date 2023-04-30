//
// Created by israel on 4/28/23.
//

#include "Fraction.hpp"

namespace ariel {
    void Fraction::reduce() {}

    Fraction::Fraction(int num, int denom) : numerator(num), denominator(denom) {}

    Fraction Fraction::operator+(const Fraction &other) const { return Fraction(1, 1); }

    Fraction Fraction::operator-(const Fraction &other) const { return Fraction(1, 1); }

    Fraction Fraction::operator*(const Fraction &other) const { return Fraction(1, 1); }

    Fraction Fraction::operator/(const Fraction &other) const { return Fraction(1, 1); }

    bool Fraction::operator==(const Fraction &other) const { return true; }

    bool Fraction::operator!=(const Fraction &other) const { return true; }

    bool Fraction::operator>(const Fraction &other) const { return true; }

    bool Fraction::operator<(const Fraction &other) const { return true; }

    bool Fraction::operator>=(const Fraction &other) const { return true; }

    bool Fraction::operator<=(const Fraction &other) const { return true; }

    Fraction Fraction::operator+(const float f) const { return Fraction(1, 1); }

    Fraction Fraction::operator-(const float f) const { return Fraction(1, 1); }

    Fraction Fraction::operator*(const float f) const { return Fraction(1, 1); }

    Fraction Fraction::operator/(const float f) const { return Fraction(1, 1); }

    bool Fraction::operator==(const float f) const { return true; }

    bool Fraction::operator!=(const float f) const { return true; }

    bool Fraction::operator>(const float f) const { return true; }

    bool Fraction::operator<(const float f) const { return true; }

    bool Fraction::operator>=(const float f) const { return true; }

    bool Fraction::operator<=(const float f) const { return true; }


    Fraction &Fraction::operator++() { return *this; } //prefix
    Fraction &Fraction::operator--() { return *this; } //prefix
    Fraction Fraction::operator++(int) { return Fraction(1, 1); } //postfix
    Fraction Fraction::operator--(int) { return Fraction(1, 1); } //postfix

//friend functions
    Fraction operator+(const float f, const Fraction &fraction) { return Fraction(1, 1); }

    Fraction operator-(const float f, const Fraction &fraction) { return Fraction(1, 1); }

    Fraction operator*(const float f, const Fraction &fraction) { return Fraction(1, 1); }

    Fraction operator/(const float f, const Fraction &fraction) { return Fraction(1, 1); }

    bool operator==(const float f, const Fraction &fraction) { return true; }

    bool operator!=(const float f, const Fraction &fraction) { return true; }

    bool operator>(const float f, const Fraction &fraction) { return true; }

    bool operator<(const float f, const Fraction &fraction) { return true; }

    bool operator>=(const float f, const Fraction &fraction) { return true; }

    bool operator<=(const float f, const Fraction &fraction) { return true; }

    std::ostream& operator<<(std::ostream &output, const Fraction &fraction) {
        return output << fraction.getNum() << "/" << fraction.getDenom();
    }

    std::istream& operator>>(std::istream &input, Fraction &fraction) { return input; }
}