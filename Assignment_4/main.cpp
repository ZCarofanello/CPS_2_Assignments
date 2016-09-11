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
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include "Fractions.h"
#include "Metrics.h"

using namespace std;

struct DataPoints {
    std::string Operation;
    double TimeTaken;
};

struct DumbInts {
    int WowAnArray[2];
};

template<typename Types>
vector<DataPoints> Speed_Testing (vector<Types> DataVector, vector<DataPoints> DataReturn);

void SplittingData (string UserInput, int UserString[]);

int BinarySearch (int Number2Find);
int LinearSearch (int Number2Find);

int main() {
    vector<Fraction> FractionVector;
    vector<double> DoubleVector;
    vector<DumbInts> IntVector;
    vector<DataPoints> RealsOperations, FractionOperations, IntegerOperations;

    string Operations[4] = {"Addition", "Subtraction", "Multiplication", "Division"};

    string ZeData;
    ifstream Input;

    Fraction Frac;
    double ZeDouble;
    DumbInts ZeInt;
    int ReadData[2];

    Input.open("Numbs.txt");
    if (Input.is_open()) {
        while (getline(Input, ZeData)) {
            SplittingData(ZeData, ReadData);

            Frac.SetValues(ReadData[0], ReadData[1]);
            ZeDouble = double(ReadData[0]) / double(ReadData[1]);
            ZeInt.WowAnArray[0] = ReadData[0];
            ZeInt.WowAnArray[1] = ReadData[1];
            DoubleVector.push_back(ZeDouble);
            FractionVector.push_back(Frac);
            IntVector.push_back(ZeInt);
        }
    }
    Input.close();

    FractionOperations = Speed_Testing(FractionVector,FractionOperations);

    RealsOperations = Speed_Testing(DoubleVector,RealsOperations);

    Metric_Check ZeTimer;
    DataPoints Holder;
    double DummyInt;
    //Doing the calculations for the Integer times
    for (int i = 0; i < 4; i++){
        switch (i){
            case 0:
                ZeTimer.StartTimer();
                for (int j = 0; (j + 1) < IntVector.size(); j++){
                    DummyInt = IntVector[j].WowAnArray[0] + IntVector[j+1].WowAnArray[1];
                }
                ZeTimer.StopTimer();
                break;
            case 1:
                ZeTimer.StartTimer();
                for (int j = 0; (j + 1) < IntVector.size(); j++){
                    DummyInt = IntVector[j].WowAnArray[0] - IntVector[j+1].WowAnArray[1];
                }
                ZeTimer.StopTimer();
                break;
            case 2:
                ZeTimer.StartTimer();
                for (int j = 0; (j + 1) < IntVector.size(); j++){
                    DummyInt = IntVector[j].WowAnArray[0] * IntVector[j+1].WowAnArray[1];
                }
                ZeTimer.StopTimer();
                break;
            case 3:
                ZeTimer.StartTimer();
                for (int j = 0; (j + 1) < IntVector.size(); j++){
                    DummyInt = IntVector[j].WowAnArray[0] / IntVector[j+1].WowAnArray[1];
                }
                ZeTimer.StopTimer();
                break;
            default:
                cerr << "I'm not sure how you got here.\n";
        }

        Holder.Operation = Operations[i];
        Holder.TimeTaken = ZeTimer.ReturnTime();
        IntegerOperations.push_back(Holder);
        ZeTimer.ResetTimer();
    }

    int NumberWidth = 8;
    int NumPrecision = 3;
    int NameWidth = 14;
    const char SEPARATOR_1 = ' ';
    cout << left << "  Operation   | Fraction |  Double  | Integer  |\n";
    cout << left << "--------------|----------|----------|----------|\n";
    for (int i = 0; i < FractionOperations.size(); i++){
        cout << left << setw(NameWidth) << setfill(' ') << Operations[i];
        cout << internal << setprecision(NumPrecision)<< setw(NumberWidth) << setfill(' ') << FractionOperations[i].TimeTaken << " us";
        cout << internal << setprecision(NumPrecision)<< setw(NumberWidth) << setfill(' ') << RealsOperations[i].TimeTaken << " us";
        cout << internal << setprecision(NumPrecision)<< setw(NumberWidth) << setfill(' ') << IntegerOperations[i].TimeTaken << " us";
        cout << endl;
    }

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
/*
int BinarySearch (int Number2Find) {

}
int LinearSearch (int Number2Find, ){

}
 */
template<typename Types>
vector<DataPoints> Speed_Testing (vector<Types> DataVector, vector<DataPoints> DataReturn) {
    Metric_Check ZeTimer;
    DataPoints Holder;
    string Operations[4] = {"Addition", "Subtraction", "Multiplication", "Division"};
    Types DummyVar;

    for (int i = 0; i < 4; i++) {
        switch (i) {
            case 0:
                ZeTimer.StartTimer();
                for (int j = 0; (j + 1) < DataVector.size(); j++) {
                    DummyVar = DataVector[j] + DataVector[j + 1];
                }
                ZeTimer.StopTimer();
                break;
            case 1:
                ZeTimer.StartTimer();
                for (int j = 0; (j + 1) < DataVector.size(); j++) {
                    DummyVar = DataVector[j] - DataVector[j + 1];
                }
                ZeTimer.StopTimer();
                break;
            case 2:
                ZeTimer.StartTimer();
                for (int j = 0; (j + 1) < DataVector.size(); j++) {
                    DummyVar = DataVector[j] * DataVector[j + 1];
                }
                ZeTimer.StopTimer();
                break;
            case 3:
                ZeTimer.StartTimer();
                for (int j = 0; (j + 1) < DataVector.size(); j++) {
                    DummyVar = DataVector[j] / DataVector[j + 1];
                }
                ZeTimer.StopTimer();
                break;
            default:
                cerr << "I'm not sure how you got here.\n";
        }

        Holder.Operation = Operations[i];
        Holder.TimeTaken = ZeTimer.ReturnTime();
        DataReturn.push_back(Holder);
        ZeTimer.ResetTimer();
    }
    return DataReturn;
}