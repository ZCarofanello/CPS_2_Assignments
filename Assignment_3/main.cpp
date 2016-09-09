/////////////////////////////////////////////////////////////////////////
// Title: Assignment 3 - Fractions
// Author: Zachary Carofanello
// CPET-321 Computational Problem Solving II Fall 2016
// Platform: CLion 2016.2.1
// Description: Working with fractions held as integers
//
// Revisions:
// Revision 1.0 29/08/2016
//
// To Do List:
// 1. Add rounding up -Done
// 2. Add rounding down - Done
// 3. Calculate integer power - Done
// 4. File I/O - Done
// 5. add output and improve output clarity - Done
/////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <fstream>
#include "Fractions.h"

using namespace std;

void ReadFromFile (string InFileName, vector<Fraction> FractionList);
void SplittingData (string UserInput, int UserString[]);
bool CheckForGarbage (string RawData);

int main() {
    vector<Fraction> FractionVector;
    Fraction Max;

    string ZeData;
    ifstream Input;
    Fraction Frac;
    int ReadData[2];

    Input.open("Numbs.txt");
    if (Input.is_open()) {
        while (getline(Input, ZeData)) {
            SplittingData(ZeData, ReadData);
            Frac.SetValues(ReadData[0], ReadData[1]);
            FractionVector.push_back(Frac);
        }
    }
    Input.close();

    Max = FractionVector[0];
    //Iterates through the vector and checks if the current fraction less than the next one
    for (int i = 1; i < FractionVector.size(); i++){
        if (Fraction::Compare(FractionVector[i],Max)){
            Max = FractionVector[i];
    }
        else{
            Max = FractionVector[i+1];
        }
    }

    Max.Simplify();

    cout << "The largest fraction in the data set is:\n";
    cout << Max.ToString() << endl;

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