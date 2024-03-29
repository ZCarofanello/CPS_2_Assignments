//
// Created by Glados on 8/30/2016.
//

#ifndef ASSIGNMENT_2_FRACTIONS_FRACTIONS_H
#define ASSIGNMENT_2_FRACTIONS_FRACTIONS_H

#include <string>

class Fraction{
public:
    //Constructors
    Fraction();
    void SetValues (int Numerator, int Denominator);
    void SetValues (int Numerator);
    ~Fraction(void);

    //Getting the Data Out
    std::string ToString (void);

    //Data Manipulation
    Fraction operator+ (const Fraction& other);
    Fraction operator* (const Fraction& other);
    Fraction operator/ (Fraction& other);
    Fraction operator- (const Fraction& other);
    void reciprocal (void);

    //Rounding Functions
    int RoundUpToInt(void);

private:
    int TotalFraction[2];
    int Whole_Number;

    void Simplify();

    int GCD(void);


//    void CheckForOverflow();

};

#endif //ASSIGNMENT_2_FRACTIONS_FRACTIONS_H
