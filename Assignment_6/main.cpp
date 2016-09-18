/////////////////////////////////////////////////////////////////////////
// Title: Assignment 6 - Aliens n Arrays
// Author: Zachary Carofanello
// CPET-321 Computational Problem Solving II Fall 2016
// Platform: CLion 2016.2.1
// Description: The problem with the aliens and other fun stuff
//
// Revisions:
// Revision 1.0 18/09/16
//
// To Do List:
// 1. Alien Problem
// 2. Checking arrays
// 3. I mean there's always something else to do
//
/////////////////////////////////////////////////////////////////////////
#include <iostream>

int * OddAndEvenCount (int Number2Check);
int AlienHandsIter (int NumberOfSeats);
int AlienHandsRec (int NumberOfSeats);

int main() {
    int UserNum;
    std::cout << "How many seats are there?" << std::endl;
    std::cin >> UserNum;
    std::cout << "The number of hands in a row " << UserNum << " seats long is " << AlienHandsRec(UserNum) << std::endl;
    system("Pause");
    return 0;
}

int AlienHandsIter (int NumberOfSeats){
    int *OddEvenCount;
    OddEvenCount = OddAndEvenCount(NumberOfSeats);
    return (*(OddEvenCount + 0) * 4) + (*(OddEvenCount + 1) * 3);
}

int AlienHandsRec (int NumberOfSeats){
    if(NumberOfSeats == 1){
        return 3;
    }
    else if(NumberOfSeats % 2 == 0) {
        return AlienHandsRec(NumberOfSeats-1) + 4;
    }
    else{
        return AlienHandsRec(NumberOfSeats-1) + 3;
    }
}

int * OddAndEvenCount (int Number2Check){
    //First index is Even and second is Odd
    static int OddAndEven[2] = {0, 0};

    //If it's zero don't bother doing the calculations
    if(Number2Check != 0) {
        if (Number2Check % 2 == 0) {
            OddAndEven[0] = Number2Check / 2;
            OddAndEven[1] = OddAndEven[0];
        } else {
            OddAndEven[1] = (Number2Check + 1) / 2;
            OddAndEven[0] = OddAndEven[1] - 1;
        }
    }
    return OddAndEven;
}
