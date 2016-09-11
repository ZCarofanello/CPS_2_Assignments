/////////////////////////////////////////////////////////////////////////
// Title: Assignment 3 - Fractions
// Author: Zachary Carofanello
// CPET-321 Computational Problem Solving II Fall 2016
// Platform: CLion 2016.2.1
// Description: Fractions class methods
//
// Revisions:
// Revision 1.0 29/08/2016
//
/////////////////////////////////////////////////////////////////////////
#include "Fractions.h"
#include <string>

Fraction::Fraction(){
    TotalFraction[0] = 0;
    TotalFraction[1] = 1;
}

void Fraction::SetValues(int Numerator, int Denominator){
    if(Denominator != 0) {
        TotalFraction[0] = Numerator;
        TotalFraction[1] = Denominator;
        Simplify();
    }
    else{
        //Oops not a valid fraction
        TotalFraction[0] = 0;
        TotalFraction[1] = 1;
    }
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

int Fraction::RoundUp (void){
    int Whole_Number;
    Whole_Number = TotalFraction[0] / TotalFraction[1];
    TotalFraction[0] = TotalFraction[1] + (TotalFraction[1]*Whole_Number);
    return Whole_Number + 1;
}

int Fraction::RoundDown(void){
    int Whole_Number;
    Whole_Number = TotalFraction[0] / TotalFraction[1];
    if (Whole_Number == 0){
        return 0;
    }
    else{
    TotalFraction[0] = (TotalFraction[1]*Whole_Number);
    return Whole_Number - 1;
    }
}

void Fraction::IntegerPower (int Power){
    if (Power < 0) {
        reciprocal();
        Power = -Power;
    }
    if (Power == 0) {
        TotalFraction[0] = 1;
        TotalFraction[1] = 1;
        //std::cout << "Power is Zero\n";
    }
    for(int i = 0; i < Power; i++){
        TotalFraction[0] *= TotalFraction[0];
        TotalFraction[1] *= TotalFraction[1];
    }
}

//Checks if the first fraction is larger than the second
bool Fraction::Compare(Fraction First, Fraction Second) {
    //Multiplies the numerators by the other denominator
    First.TotalFraction[0] *= Second.TotalFraction[1];
    Second.TotalFraction[0] *= First.TotalFraction[1];

    //Checks if the first fraction is greater the second
    if(First.TotalFraction[0] > Second.TotalFraction[0]){
        return 1;
    }
    else
        return 0;
}

//Simplifies the Fraction using gcd
void Fraction::Simplify(void){
    int d = GCD();
    TotalFraction[0] = TotalFraction[0]/  d;
    TotalFraction[1] = TotalFraction[1]/  d;
}

//Simple GCD function
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