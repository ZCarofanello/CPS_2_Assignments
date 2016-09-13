/////////////////////////////////////////////////////////////////////////
// Title: Assignment 3 - Fractions
// Author: Zachary Carofanello
// CPET-321 Computational Problem Solving II Fall 2016
// Platform: CLion 2016.2.1
// Description: Header for Fraction class
//
// Revisions:
// Revision 1.0 29/08/2016
//
/////////////////////////////////////////////////////////////////////////

#ifndef ASSIGNMENT_2_FRACTIONS_FRACTIONS_H
#define ASSIGNMENT_2_FRACTIONS_FRACTIONS_H

#include <string>
#include <vector>

class Fraction{
public:
    //Constructors
    Fraction();
    ~Fraction(void);
    void SetValues (int Numerator, int Denominator);
    void SetValues (int Numerator);
    //static void Add2Vector (std::vector MyVect, int Numerator, int Denominator);

    //Getting the Data Out
    std::string ToString (void);

    //Data Manipulation
    Fraction operator+ (const Fraction& other);
    Fraction operator* (const Fraction& other);
    Fraction operator/ (Fraction& other);
    Fraction operator- (const Fraction& other);
    void reciprocal (void);
    void IntegerPower (int Power);

    static bool Compare (Fraction First, Fraction Second);

    //Rounding Functions
    int RoundUp(void);
    int RoundDown(void);

    void Simplify();

private:
    //Holds the numerator in the first cell and denominator in second
    int TotalFraction[2];

    int GCD(void);


//    void CheckForOverflow();

};

#endif //ASSIGNMENT_2_FRACTIONS_FRACTIONS_H
