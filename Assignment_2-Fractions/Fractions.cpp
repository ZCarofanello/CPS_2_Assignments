//
// Created by Zack on 8/30/2016.
//
#include <string>
#include <iostream>

using namespace std;

class Fraction{
    int TotalFraction[2];
public:
    //All these overloaded inputs
    void SetValues (int Numerator, int Denominator);
    void SetValues (double Numerator, double Denominator);
    void SetValues (int Numerator);
    void SetValues (double Numerator);
    void SetValues (void);

    //Getting the Data Out
    string display_frac (void);

    //Data Manipulation
    Fraction operator+ (const Fraction& other);
    Fraction operator* (const Fraction& other);
    Fraction operator/ (const Fraction& other);
    Fraction operator- (const Fraction& other);

private:
    void Simplify();

    void CheckForOverflow();

};

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

string Fraction::display_frac() {
    Fraction::Simplify();
    cout << TotalFraction[0] << "/" << TotalFraction[1];
}

Fraction Fraction::operator+(const Fraction &other) {

}

