//
// Created by Glados on 8/30/2016.
//

#ifndef ASSIGNMENT_2_FRACTIONS_FRACTIONS_H
#define ASSIGNMENT_2_FRACTIONS_FRACTIONS_H

class Fraction{
public:
    //All these overloaded inputs
    void SetValues (int Numerator, int Denominator);
    void SetValues (int Numerator);
    void SetValues (void);

    //Getting the Data Out
    void display (void);

    //Data Manipulation
    Fraction operator+ (const Fraction& other);
    Fraction operator* (const Fraction& other);
    Fraction operator/ (Fraction& other);
    Fraction operator- (const Fraction& other);
    void reciprocal (void);

private:
    int TotalFraction[2];

    void Simplify();

    int GCD(int Fraction[]);


//    void CheckForOverflow();

};

#endif //ASSIGNMENT_2_FRACTIONS_FRACTIONS_H
