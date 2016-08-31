//
// Created by Zack on 8/30/2016.
//
#include "Fractions.h"
#include <iostream>

void Fraction::SetValues() {
    TotalFraction[0] = 0;
    TotalFraction[1] = 1;
}

void Fraction::SetValues(int Numerator, int Denominator) {
    TotalFraction[0] = Numerator;
    TotalFraction[1] = Denominator;
}

void Fraction::SetValues(int Numerator) {
    TotalFraction[0] = Numerator;
    TotalFraction[1] = 1;
}

void Fraction::display() {
    //Fraction::Simplify();
    std::cout << TotalFraction[0] << "/" << TotalFraction[1];
}

Fraction Fraction::operator+(const Fraction &other) {
    Fraction Result;
    Result.TotalFraction[0] = (this->TotalFraction[0] * other.TotalFraction[1]) + (other.TotalFraction[0] * this->TotalFraction[1]);
    Result.TotalFraction[1] = (this->TotalFraction[1] * other.TotalFraction[1]);
    return Result;
}

Fraction Fraction::operator-(const Fraction &other) {
    Fraction Result;
    Result.TotalFraction[0] = (this->TotalFraction[0]*other.TotalFraction[1]) - (other.TotalFraction[0]*this->TotalFraction[1]);
    Result.TotalFraction[1] = (this->TotalFraction[1] * other.TotalFraction[1]);
    return Result;
}

Fraction Fraction::operator*(const Fraction &other) {
    Fraction Result;
    Result.TotalFraction[0] = (this->TotalFraction[0]*other.TotalFraction[0]);
    Result.TotalFraction[1] = (this->TotalFraction[1]*other.TotalFraction[1]);
    return Result;
}

Fraction Fraction::operator/(Fraction &other) {
    Fraction Result;
    other.reciprocal();
    Result.TotalFraction[0] = (this->TotalFraction[0]*other.TotalFraction[0]);
    Result.TotalFraction[1] = (this->TotalFraction[1]*other.TotalFraction[1]);
    return Result;
}

void Fraction::reciprocal (void) {
    int holding_variable = 0;
    holding_variable = TotalFraction[0];
    TotalFraction[0] = TotalFraction[1];
    TotalFraction[1] = holding_variable;
}