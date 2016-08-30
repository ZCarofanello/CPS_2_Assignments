/////////////////////////////////////////////////////////////////////////
// Title: Assignment 1 - Number Swap
// Author: Zachary Carofanello
// CPET-321 Computational Problem Solving II Fall 2016
// Platform: CLion 2016.2.1
// Description: Examples on how to swap two numbers in various ways
//
// Revisions:
// Revision 1.0 23/08/2016
// Wrote extra way to swap numbers
// Added choice to select file or input
//
// To Do List:
// 1. Implement one more way without using third variable. - Done
// 2. Add code for swapping other numeric data types other than integers such as float, double. -Done
// 3. Add Error checking (try, catch and finally)
// 4. Make the program read input from file and write output to file.
// 5. Add double type back in but it seems like a pain to tell difference
/////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include "Text_File_Encoder.h"

using namespace std;

struct NumberHolder

class NumberManagement {
    int NumbersAreInts[2];
    double NumbersAreDoubles[2];
    string SplitData[2];
    string RawData;
    public:
        void TypeChecking ();
        void SplittingData (string RawData);
    template <typename Types>
    void SwapNumbers(Types NumbersToSwap[]){
        //swapping using third variable
        Types temp = NumbersToSwap[1];
        NumbersToSwap[1] = NumbersToSwap[2];
        NumbersToSwap[2] = temp;
        cout << "Values after swapping are:\n" << endl;
        cout << "x: " << NumbersToSwap[1] << " y: " << NumbersToSwap[2] << endl;

        // swapping without third variable
        NumbersToSwap[1] = NumbersToSwap[1] + NumbersToSwap[2];
        NumbersToSwap[2] = NumbersToSwap[1] - NumbersToSwap[2];
        NumbersToSwap[1] = NumbersToSwap[1] - NumbersToSwap[2];
        cout << "Values after swapping are:\n";
        cout << "x: " << NumbersToSwap[1] << " y: " << NumbersToSwap[2] << endl;

        // swapping another way without another variable
        NumbersToSwap[1] ^= NumbersToSwap[2];
        NumbersToSwap[2] ^= NumbersToSwap[1];
        NumbersToSwap[1] ^= NumbersToSwap[2];
        cout << "Values after swapping are:\n";
        cout << "x: " << NumbersToSwap[1] << " y: " << NumbersToSwap[2] << endl;
    }
        void InputRawData(string UserInput){
            RawData = UserInput;
        }
        void InputSplitData(string UserInput, int Position){
            SplitData[Position] = UserInput;
        }
};

bool CheckForGarbage (string RawData);

template <typename Types>
void SwapNumbers(Types NumbersToSwap[]);

int main() {
    //Initializing string to find input
    string User_Input = "";
    NumberManagement NumberSet1;

    //Asking user to select to open a file or to input data
    cout << "Do you want to open a file or input values?\n";
    cout << "1. Open File\n2. Input Values\nPlease Enter 1 or 2: ";
    cin >> User_Input;

    while(User_Input != "1" && User_Input != "2"){
        cout << "\nPlease enter a valid input.\n\n";
        cout << "Do you want to open a file or input values?\n";
        cout << "1. Open File\n2. Input Values\nPlease Enter 1 or 2: ";
        cin.clear();
        cin.ignore();
        cin >> User_Input;
    }
    switch (User_Input.at(0)) {
        case '1': {
            cout << "What is the name of the file you're trying to open?\n";
            cin >> User_Input;
            break;
        }
        case '2': {
            cout << "Enter 1st value: ";
            cin >> User_Input;
            while(!CheckForGarbage(User_Input)){
                cout << "Please enter a valid Number.\n";
                cout << "Enter 1st value: ";
                cin >> User_Input;
            }
            NumberSet1.InputSplitData(User_Input,1);

            cout << "Enter 2nd value: ";
            cin >> User_Input;
            while(!CheckForGarbage(User_Input)){
                cout << "Please enter a valid Number.\n";
                cout << "Enter 2nd value: ";
                cin >> User_Input;
            }
            NumberSet1.InputSplitData(User_Input,2);
            NumberSet1.SwapNumbers()

            //SwappinNumbers(Number1, Number2);
          //  cout << "Values after swapping are:\n";
          //  cout << "x: " << Number1.IntNum << " y: " << Number2.IntNum<< endl;
            break;

            //Default Case to catch cosmic ray interference or incredibly gifted users
            default:
                cout << "I really don't know how you got in here but this is awkward....\n";
                exit(1);

        }
    }

    system("pause");
}



bool CheckForGarbage (string RawData){
    bool isValidNumber = false;
    for(int i = 0; i < RawData.length(); i++){
        if(isalnum(RawData[i]) == 0 && RawData[i] != '.'){
            cout << "Not a valid number\n";
            break;
        }
        else if (RawData.length() == i){
            isValidNumber = 1;
        }
    }
    return isValidNumber;
}

void NumberManagement::TypeChecking() {
    bool OneIsADouble = 0;
    for (int j = 0; j < 2; j++) {
        if(OneIsADouble){
            NumbersAreDoubles[1] = stod(SplitData[1]);
            NumbersAreDoubles[2] = stod(SplitData[2]);
        }
        else {
            for (unsigned int i = 0; i < SplitData[j].length(); i++) {
                if (SplitData[j].at(i) == '.') {
                    NumbersAreDoubles[j] = stod(SplitData[j]);
                    OneIsADouble = 1;
                    break;
                } else if (i + 1 == SplitData[j].length()) {
                    NumbersAreInts[j] = stoi(SplitData[j]);
                }
            }
        }
    }
}