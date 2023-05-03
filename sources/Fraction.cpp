//
// Created by israel on 4/28/23.
// I got some help from StackOverflow about operators overloading.
//

#include "Fraction.hpp"
#include <algorithm> // For std::abs and std::__gcd
#include <limits> // For std::numeric_limits


namespace ariel {
    // Reduces the fraction and ensures the denominator is positive.
    void Fraction::reduce() {
        if (denominator == 0) {
            throw std::invalid_argument("Denominator cannot be zero");
        }
        if (numerator == 0) {
            denominator = 1;
            return;
        }
        int gcd = std::__gcd(std::abs(numerator), std::abs(denominator)); // Uses std::__gcd to calculate the greatest common divisor.
        numerator /= gcd;
        denominator /= gcd;
        if (denominator < 0) { // Ensures the denominator is positive.
            numerator = -numerator;
            denominator = -denominator;
        }
    }

    // Constructs a fraction with the given numerator and denominator.
    Fraction::Fraction(int num, int denom) : numerator(num), denominator(denom){
        reduce();
    }

    // Constructs a fraction with the given float.
    Fraction::Fraction(float flo) : numerator(static_cast<int>(flo * 1000)), denominator(1000){
        reduce();
    }

    // Empty constructor - constructs a fraction representing zero.
    Fraction::Fraction() : numerator(0), denominator(1){
    }

    // Prefix increment
    Fraction& Fraction::operator++() {
        numerator += denominator;
        return *this;
    }

    // Prefix decrement
    Fraction& Fraction::operator--() {
        numerator -= denominator;
        return *this;
    }

    // Postfix increment
    Fraction Fraction::operator++(int) {
        Fraction temp(*this);
        numerator += denominator;
        return temp;
    }

    // Postfix decrement
    Fraction Fraction::operator--(int) {
        Fraction temp(*this);
        numerator -= denominator;
        return temp;
    }

    // Helper function that checks for overflow.
    void is_overflow(long long numerator, long long denominator){
        if (numerator > std::numeric_limits<int>::max() || denominator > std::numeric_limits<int>::max() ||
        numerator < std::numeric_limits<int>::min() || denominator < std::numeric_limits<int>::min()){
            throw std::overflow_error("Overflow error: numerator or denominator too large/small.");
        }
    }

    // Adds two fractions.
    Fraction operator+(const Fraction& fraction_1, const Fraction& fraction_2) {
        long long numerator = static_cast<long long>(fraction_1.numerator) * fraction_2.denominator + static_cast<long long>(fraction_2.numerator) * fraction_1.denominator;
        long long denominator = static_cast<long long>(fraction_1.denominator) * fraction_2.denominator;
        is_overflow(numerator, denominator);
        Fraction result = Fraction(numerator, denominator);
        result.reduce();
        return result;
    }

    // Subtracts one fraction from another.
    Fraction operator-(const Fraction& fraction_1, const Fraction& fraction_2) {
        long long numerator = static_cast<long long>(fraction_1.numerator) * fraction_2.denominator - static_cast<long long>(fraction_2.numerator) * fraction_1.denominator;
        long long denominator = static_cast<long long>(fraction_1.denominator) * fraction_2.denominator;
        is_overflow(numerator, denominator);
        Fraction result = Fraction(numerator, denominator);
        result.reduce();
        return result;
    }

    // Multiplies two fractions.
    Fraction operator*(const Fraction& fraction_1, const Fraction& fraction_2) {
        long long numerator = static_cast<long long>(fraction_1.numerator) * fraction_2.numerator;
        long long denominator = static_cast<long long>(fraction_1.denominator) * fraction_2.denominator;
        is_overflow(numerator, denominator);
        Fraction result = Fraction(numerator, denominator);
        result.reduce();
        return result;
    }

    // Divides two fractions.
    Fraction operator/(const Fraction& fraction_1, const Fraction& fraction_2) {
        if (fraction_2.numerator == 0) {
            throw std::runtime_error("Cannot divide by zero");
        }
        long long numerator = static_cast<long long>(fraction_1.numerator) * fraction_2.denominator;
        long long denominator = static_cast<long long>(fraction_1.denominator) * fraction_2.numerator;
        is_overflow(numerator, denominator);
        Fraction result = Fraction(numerator, denominator);
        result.reduce();
        return result;
    }

    // Check equalization between two fractions.
    bool operator==(const Fraction& fraction_1, const Fraction& fraction_2) {
        if(fraction_1.numerator * fraction_2.denominator == fraction_2.numerator * fraction_1.denominator){return true;}
        return false;

//        float fraction1_as_flo = static_cast<int>(static_cast<float>(fraction_1.numerator) / fraction_1.denominator * 1000);
//        float fraction2_as_flo = static_cast<int>(static_cast<float>(fraction_2.numerator) / fraction_2.denominator * 1000);
//        return fraction1_as_flo==fraction2_as_flo;
    }

    // Check if one fraction is greater than other fraction.
    bool operator>(const Fraction& fraction_1, const Fraction& fraction_2) {
        return fraction_1.numerator * fraction_2.denominator > fraction_2.numerator * fraction_1.denominator;
    }

    // Check if one fraction is less than other fraction.
    bool operator<(const Fraction& fraction_1, const Fraction& fraction_2) {
        return fraction_1.numerator * fraction_2.denominator < fraction_2.numerator * fraction_1.denominator;
    }

    // Check if one fraction is greater than/ equal to other fraction.
    bool operator>=(const Fraction& fraction_1, const Fraction& fraction_2) {
        return fraction_1 > fraction_2 || fraction_1 == fraction_2;
    }

    // Check if one fraction is less than/ equal to other fraction.
    bool operator<=(const Fraction& fraction_1, const Fraction& fraction_2) {
        return fraction_1 < fraction_2 || fraction_1 == fraction_2;
    }

    // Takes an output stream object and a constant reference to a Fraction object as input.
    std::ostream& operator<<(std::ostream& output, const Fraction& fraction) {
        output << fraction.numerator << "/" << fraction.denominator; // Output the fraction in the format "numerator/denominator"
        return output;
    }

    // Takes an input stream object and a reference to a Fraction object as input.
    std::istream& operator>>(std::istream& input, Fraction& fraction) {
        int num, denom;
        input >> num >> denom;
        if (input.fail() || denom == 0) { // Check if the input operation failed or if the denominator is zero. If yes - throws exception.
            throw std::runtime_error("Invalid input");
        }
        fraction.setNumerator(num);
        fraction.setDenominator(denom);
        fraction.reduce();
        return input;
    }
}