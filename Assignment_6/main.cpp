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
#include <cstdlib>
#include <cmath>
#include <vector>
#include "metrics.h"

using namespace std;

struct DataPoints {
    std::string Operation;
    double TimeTaken;
};



int * OddAndEvenCount (int Number2Check);
int AlienHandsIter (int NumberOfSeats);
int AlienHandsRec (int NumberOfSeats);
bool ArrayChecking (int Array[][4], int Size);

int main() {
    int max_data_set = 10000;

    vector<DataPoints> AlienRec, AlienIter;
    vector<int> TestData;
    DataPoints Holder;
    Metric_Check ZeTimer;

    int NumArray[][4] = { 1, 2, 3, 4,
                          2, 1, 2, 3,
                          3, 2, 1, 2,
                          4, 3, 2, 1};
    if(ArrayChecking(NumArray, 4)){
        cout << "It's Symmetrical!\n";
    }
    else
        cout << "It's not Symmetrical\n";

    for(int i = 0; i <= max_data_set; i++)
        TestData.push_back(rand() % (2*max_data_set));

    for(int k=0; k < 2; k++) {
        for (int i = 0; i < 3; i++) {
            int Data_Set_Size = pow(10,i+2);
            int IntHolder;
            ZeTimer.StartTimer();
            for (int j = 0; j < (Data_Set_Size-1); j++) {
                if(k == 0)
                    IntHolder = AlienHandsIter(TestData[j]);
                else
                    IntHolder = AlienHandsRec(TestData[j]);
            }
            ZeTimer.StopTimer();
            if (k == 0) {
                Holder.Operation = "Iterative";
                Holder.TimeTaken = ZeTimer.ReturnTime();
                AlienIter.push_back(Holder);
            }
            else {
                Holder.Operation = "Recursve";
                Holder.TimeTaken = ZeTimer.ReturnTime();
                AlienRec.push_back(Holder);
            }
            ZeTimer.ResetTimer();
        }
    }

    for(int i = 0; i < 3; i++){
        cout << AlienIter[i].Operation << " " << AlienIter[i].TimeTaken << endl;
        cout << AlienRec[i].Operation << " " << AlienRec[i].TimeTaken << endl;
    }

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

bool ArrayChecking (int Array[][4], int Size){
    if(Size == 1)
        return true;
    else{
        bool KeepGoin = false;
        for(int i = 0; i < (Size - 1); i++){
            if(Array[Size - 1][i] != Array[i][Size - 1]){
                KeepGoin = false;
            }
            else
                KeepGoin = true;
            }
            if (KeepGoin)
                ArrayChecking(Array, Size-1);
            else
                return  false;
        }
}
