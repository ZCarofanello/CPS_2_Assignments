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
#include <fstream>
#include <cctype>

using namespace std;

union Nums2Swap {
    int IntNum;
    float FloatNum;
};

//Overloading functions to allow for other data types
int* SwappinNumbers (int Nums[]);
double* SwappinNumbers (double Nums[]);
float* SwappinNumbers (float Nums[]);

//File I/O fucntions
//string FileOpener (string FileName);
//string FileCreation (string Filename);

//Data Type Tester
Nums2Swap CheckTypes (string UnknownData);

int main() {
    //Initializing string to find input
    string User_Input = "";

    //Data to hold number values
    union Nums2Swap Number1, Number2;

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
            //FileOpener(User_Input);
            break;
        }
        case '2': {
            cout << "Enter 1st value: ";
            cin >> User_Input;
            Number1 = CheckTypes(User_Input);
            cout << "Enter 2nd value: ";
            cin >> User_Input;
            Number2 = CheckTypes(User_Input);
            break;

        }
    }

    // swapping using third variable
//    int temp = x;
//    x = y;
//    y = temp;
//    cout << "Values after swapping are:\n" << endl;
//    cout << "x: " << x << " y: " << y << endl;

    // swapping without third variable
//    x = x + y;
//    y = x - y;
//    x = x - y;
//    cout << "Values after swapping are:\n";
//    cout << "x: " << x << " y: " << y << endl;

    // swapping another way without another variable
//    x ^= y;
//    y ^= x;
//    x ^= y;
//    cout << "Values after swapping are:\n";
//    cout << "x: " << x << " y: " << y << endl;

    system("pause");
}

int* SwappinNumbers (int Nums[]){
    Nums[0] = Nums[0] + Nums[1];
    Nums[1] = Nums[0] - Nums[1];
    Nums[0] = Nums[0] - Nums[1];
    return Nums;
}

float* SwappinNumbers (float Nums[]){
    Nums[0] = Nums[0] + Nums[1];
    Nums[1] = Nums[0] - Nums[1];
    Nums[0] = Nums[0] - Nums[1];
    return Nums;
}

double* SwappinNumbers (double Nums[]){
    Nums[0] = Nums[0] + Nums[1];
    Nums[1] = Nums[0] - Nums[1];
    Nums[0] = Nums[0] - Nums[1];
    return Nums;
}

/*
string FileOpener (string UserInput) {
    string NumberRead;
    ofstream myfile;
    myfile.open (UserInput, ios::in);
    if (myfile.is_open()){
        while(myfile.good()){
            getline(myfile,NumberRead)
        }
    }
}
*/

Nums2Swap CheckTypes (string UnknownData){

    Nums2Swap SelectedData;
    string::size_type sz;
    for(unsigned int i = 0; i < UnknownData.length(); i++){
        if(UnknownData.at(i) == '.'){
            SelectedData.FloatNum = stof(UnknownData,&sz);
            break;
        }
        else if(i+1 == UnknownData.length()){
            SelectedData.IntNum = stoi(UnknownData,&sz);
        }
    }
    return SelectedData;
}

bool CheckForGarbage (string DataIn){
    bool isValidNumber = false;
    for(int i = 0; i < DataIn.length(); i++){
        if(isalnum(DataIn[i]) == false && DataIn[i] != '.'){
            cout << "Not a valid number\n";
            break;
        }
        else if (DataIn.length() == i){
            isValidNumber = true;
        }
    }
    return isValidNumber;
}
