/////////////////////////////////////////////////////////////////////////
// Title: Assignment 4 - Fractions and Efficiency Metrics
// Author: Zachary Carofanello
// CPET-321 Computational Problem Solving II Fall 2016
// Platform: CLion 2016.2.1
// Description: Working with fractions held as integers
//
// Revisions:
// Revision 1.0 10/09/2016
//
// To Do List:
// 1. Create a sorting method
// 2. Code the search methods
// 3. Finish the Metrics Class
// 4. Create a way to compare the operations between reals and
//    the fraction way.
/////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <fstream>
#include "Fractions.h"
#include "Metrics.h"

using namespace std;

void ReadFromFile (string InFileName, vector<Fraction> FractionList);
void SplittingData (string UserInput, int UserString[]);
bool CheckForGarbage (string RawData);


int BinarySearch (int Number2Find);
int LinearSearch (int Number2Find);

int main() {
    vector<Fraction> FractionVector;
    vector<double> DoubleVector;


    string ZeData;
    ifstream Input;

    Fraction Frac;
    double ZeDouble;
    int ReadData[2];

    Input.open("Numbs.txt");
    if (Input.is_open()) {
        while (getline(Input, ZeData)) {
            SplittingData(ZeData, ReadData);

            Frac.SetValues(ReadData[0], ReadData[1]);
            ZeDouble = double(ReadData[0]) / double(ReadData[1]);

            DoubleVector.push_back(ZeDouble);
            FractionVector.push_back(Frac);
        }
    }
    Input.close();



    system("pause");

}

void SplittingData (string UserInput, int UserString[]){
    string delimiter = " ";
    size_t pos = 0;
    string FoundNum;
    int i = 0;

    while ((pos = UserInput.find(delimiter)) != std::string::npos) {
        FoundNum = UserInput.substr(0, pos);
        UserString[i] = stoi(FoundNum);
        UserInput.erase(0, pos + delimiter.length());
        i++;
    }
}

bool CheckForGarbage (string RawData){
    bool isValidNumber = false;
    for(int i = 0; i < RawData.length(); i++){
        if(isalnum(RawData[i]) == 0 || RawData[i] == '.'){
            cout << "Not a valid number\n";
            break;
        }
        else if (RawData.length() == i){
            isValidNumber = 1;
        }
    }
    return isValidNumber;
}
/*
int BinarySearch (int Number2Find) {

}
int LinearSearch (int Number2Find, ){

}
 */