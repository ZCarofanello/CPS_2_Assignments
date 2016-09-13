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
// 1. Code the search methods
// 2. Finish the Metrics Class
// 3. Create a way to compare the operations between reals and
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

//A container to keep the operation times and a description of what time it is
struct DataPoints {
    std::string Operation;
    double TimeTaken;
};

//This was made because Ints can't be held in a vector as an array on their own
struct DumbInts {
    int WowAnArray[2];
};

//Function for the search methods
template<typename Types>
vector<DataPoints> Speed_Testing (vector<Types> DataVector, vector<DataPoints> DataReturn);

//Function for the search methods
template<typename DataType>
DataPoints SearchTest (DataType Number2Find, vector<DataType> ListToSearch, int SearchMethod);

void SplittingData (string UserInput, int UserString[]);

int main() {
    //All the vectors for the data
    vector<Fraction> FractionVector;
    vector<double> DoubleVector;
    vector<DumbInts> IntVector;
    vector<DataPoints> RealsOperations, FractionOperations, IntegerOperations, SearchOperations;
    vector<int> SortedList = {13,16,25,28,32,36,40,72,105,107,111,112,118,136,139,196,213,220,223,229,241,259,292,301,303,325,328,340,342,422,429,431,441,446,450,468,488,501,505,551,567,568,575,584,597,598,599,608,617,618,635,636,640,650,652,658,662,664,665,678,688,689,695,698,699,718,727,734,742,747,751,752,759,764,773,774,779,780,785,787,791,792,794,798,802,823,836,837,847,848,877,885,890,920,921,932,946,958,964,989};

    string Operations[4] = {"Addition", "Subtraction", "Multiplication", "Division"};

    //Reading in the data from a txt document
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

    //Testing the operation speed of the Fraction class
    FractionOperations = Speed_Testing(FractionVector,FractionOperations);
    //Testing the operation speed of double operations
    RealsOperations = Speed_Testing(DoubleVector,RealsOperations);

    //The integers are held differently so I had to put it into the main()
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

    //Testing the search time for linear search
    SearchOperations.push_back(SearchTest(551,SortedList,1));
    //Testing the search time for binary search
    SearchOperations.push_back(SearchTest(551,SortedList,2));

    //Prints out and formats the data into a table
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
    cout << endl;
    cout << left << "  Operation   | Binary   |  Linear  |\n";
    cout << left << "--------------|----------|----------|\n";
    cout << left << setw(NameWidth) << setfill(' ') << "Search" << endl;
    cout << internal << setprecision(NumPrecision)<< setw(NumberWidth) << setfill(' ') << SearchOperations[0].TimeTaken << " us";
    cout << internal << setprecision(NumPrecision)<< setw(NumberWidth) << setfill(' ') << SearchOperations[1].TimeTaken << " us";
    cout << endl;

    system("pause");
}

//Splits a string up into ints
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

//Function to measure the time it takes to find a number using different methods
template<typename DataType>
DataPoints SearchTest (DataType Number2Find, vector<DataType> ListToSearch, int SearchMethod){
    Metric_Check TheTimer;
    DataPoints Holder;
    switch(SearchMethod){
        case 1: {
            for (int i = 0; i < ListToSearch.size(); i++) {
                TheTimer.StartTimer();
                if (Number2Find == ListToSearch[i]) {
                    TheTimer.StopTimer();
                    break;
                }
            }
            Holder.Operation = "Linear_Search";
            break;
        }
        case 2:{
            //creates the starting and end index for search
            int low = 0;
            int high = ListToSearch.size() -1;

            //Starts the timer
            TheTimer.StartTimer();
            //checks if everything ok
            while(low <= high) {
                //finds middle of the two indices
                int mid = (low+high)/2;

                //Less than the value
                if(Number2Find < ListToSearch[mid])
                    high = mid - 1;
                //Greater than the value
                else if(Number2Find > ListToSearch[mid])
                    low = mid + 1;
                //Found the number
                else {
                    TheTimer.StopTimer();
                    break;
                }
            }
            Holder.Operation = "Binary_Search";
            break;
            }
        default:{
            cerr << "Oops you didn't set this up correctly!\n";
        }
    }
    Holder.TimeTaken = TheTimer.ReturnTime();
    return Holder;
}

//Just a switch / looping structure to loop through the data set then record the time taken
template<typename Types>
vector<DataPoints> Speed_Testing (vector<Types> DataVector, vector<DataPoints> DataReturn) {
    Metric_Check ZeTimer;
    DataPoints Holder;
    string Operations[4] = {"Addition", "Subtraction", "Multiplication", "Division"};
    Types DummyVar;

    for (int i = 0; i < 4; i++) {
        switch (i) {
            case 0: //Testing the addition times
                ZeTimer.StartTimer();
                for (int j = 0; (j + 1) < DataVector.size(); j++) {
                    DummyVar = DataVector[j] + DataVector[j + 1];
                }
                ZeTimer.StopTimer();
                break;
            case 1: //Testing the subtraction times
                ZeTimer.StartTimer();
                for (int j = 0; (j + 1) < DataVector.size(); j++) {
                    DummyVar = DataVector[j] - DataVector[j + 1];
                }
                ZeTimer.StopTimer();
                break;
            case 2: //Testing the multiplication times
                ZeTimer.StartTimer();
                for (int j = 0; (j + 1) < DataVector.size(); j++) {
                    DummyVar = DataVector[j] * DataVector[j + 1];
                }
                ZeTimer.StopTimer();
                break;
            case 3: //Testing the division times
                ZeTimer.StartTimer();
                for (int j = 0; (j + 1) < DataVector.size(); j++) {
                    DummyVar = DataVector[j] / DataVector[j + 1];
                }
                ZeTimer.StopTimer();
                break;
            default:
                cerr << "I'm not sure how you got here.\n";
        }
        //Records the Operation done
        Holder.Operation = Operations[i];
        //Records the Time taken
        Holder.TimeTaken = ZeTimer.ReturnTime();
        //Copies the data into a Vector
        DataReturn.push_back(Holder);
        //Resets the timer for the next test
        ZeTimer.ResetTimer();
    }
    return DataReturn;
}