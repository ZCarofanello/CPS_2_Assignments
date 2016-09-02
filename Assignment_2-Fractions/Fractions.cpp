//
// Created by Zack on 8/30/2016.
//
#include "Fractions.h"
#include <string>

Fraction::Fraction(){
    TotalFraction[0] = 0;
    TotalFraction[1] = 1;
    Whole_Number = 0;
}

void Fraction::SetValues(int Numerator, int Denominator) {
    TotalFraction[0] = Numerator;
    TotalFraction[1] = Denominator;
}

void Fraction::SetValues(int Numerator) {
    TotalFraction[0] = Numerator;
    TotalFraction[1] = 1;
}

Fraction::~Fraction(void)
{
}

std::string Fraction::ToString(void)
{
    Simplify();
    char x[10];
    snprintf(x,10,"%d",TotalFraction[0]);
    char y[10];
    snprintf(y,10,"%d",TotalFraction[1]);
    std::string z = x;
    z += "/";
    z += y;
    return z;
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

int Fraction::RoundUpToInt (void){

}

void Fraction::Simplify(void){
    int d = GCD();
    TotalFraction[0] /= d;
    TotalFraction[1] /= d;
}

int Fraction::GCD() {
    int big = abs(TotalFraction[0]);
    int small = abs(TotalFraction[1]);
    int remainder = big % small;
    while (remainder != 0)
    {
        big = small;
        small = remainder;
        remainder = big % small;
    }
    return small;
}