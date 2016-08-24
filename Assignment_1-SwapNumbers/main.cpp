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
// 2. Add code for swapping other numeric data types other than integers such as float, double.
// 3. Add Error checking (try, catch and finally)
// 4. Make the program read input from file and write output to file.
/////////////////////////////////////////////////////////////////////////

#include <iostream>
//#include <string>
//#include <fstream>

using namespace std;

int main() {
    int x = 0;
    int y = 0;
    int input = 0;

    //Asking user to select to open a file or to input data
    cout << "Do you want to open a file or input values?\n";
    cout << "1. Open File\n2. Input Values\nPlease Enter 1 or 2: ";
    cin >> input;
    while(!cin || input > 2){
        cout << "\nPlease enter a valid input.\n\n";
        cout << "Do you want to open a file or input values?\n";
        cout << "1. Open File\n2. Input Values\nPlease Enter 1 or 2: ";
        cin.clear();
        cin.ignore();
        cin >> input;
    }
    cout << "You chose " << input << endl;
    cout << "Enter 1st value: ";
    cin >> x;
    cout << "Enter 2nd value: ";
    cin >> y;
    cout << "Values before swapping are:\n" << endl;
    cout << "x: " << x << " y: " << y << endl;

    // swapping using third variable
    int temp = x;
    x = y;
    y = temp;
    cout << "Values after swapping are:\n" << endl;
    cout << "x: " << x << " y: " << y << endl;

    // swapping without third variable
    x = x + y;
    y = x - y;
    x = x - y;
    cout << "Values after swapping are:\n";
    cout << "x: " << x << " y: " << y << endl;

    // swapping another way without another variable
    x ^= y;
    y ^= x;
    x ^= y;
    cout << "Values after swapping are:\n";
    cout << "x: " << x << " y: " << y << endl;

    system("pause");
}