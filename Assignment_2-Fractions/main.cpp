/////////////////////////////////////////////////////////////////////////
// Title: Assignment 2 - Fractions
// Author: Zachary Carofanello
// CPET-321 Computational Problem Solving II Fall 2016
// Platform: CLion 2016.2.1
// Description: Working with fractions held as integers
//
// Revisions:
// Revision 1.0 29/08/2016
//
// To Do List:
// 1. Add rounding up
// 2. Add rounding down
// 3. Calculate integer power
// 4. add output and improve output clarity
/////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "Fractions.h"


int main() {
    Fraction Frac1, Frac2, Result;

    Frac1.SetValues(2,3);
    Frac2.SetValues(1,3);

    std::cout << "fraction 1 is: ";
    std::cout << Frac1.ToString() << std::endl;
    std::cout << "\n\nfraction 2 is: ";
    std::cout << Frac2.ToString() << std::endl;

    std::cout << "\n\nThe sum of fraction 1 and 2 is: ";
    Result = Frac1 + Frac2;
    std::cout << Result.ToString() << std::endl;

    std::cout << "\n\nThe difference of fraction 1 and 2 is: ";
    Result = Frac1 - Frac2;
    std::cout << Result.ToString() << std::endl;

    std::cout << "\n\nThe product of fraction 1 and 2 is: ";
    Result = Frac1 * Frac2;
    std::cout << Result.ToString() << std::endl;

    std::cout << "\n\nThe quotient of fraction 1 and 2 is: ";
    Result = Frac1 / Frac2;
    std::cout << Result.ToString() << std::endl;
    std::cout << "\n";
    system("pause");

}