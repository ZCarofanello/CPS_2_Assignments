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
/////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void SplittingData (string RawData, double UserInput[]);

bool CheckForGarbage (string RawData);

string ReadWriteFromFile (string InFileName,string OutFileName, int Mode, double *UserData);

void SwapNumbers(double NumbersToSwap[]);

int main() {
    //Initializing string to find input
    string FileUserSelect, FileSaveSelect, User_Input, FileName;

    //The variables I'm using for the operations
    double JustSomeDubs[2] = {0,0};
    int File_IO_Mode = 1;

    //Asking user to select to open a file or to input data
    cout << "Do you want to open a file or input values?\n";
    cout << "1. Open File\n2. Input Values\nPlease Enter 1 or 2: ";
    cin >> FileUserSelect;

    while(FileUserSelect != "1" && FileUserSelect != "2"){
        cout << "\nPlease enter a valid input.\n\n";
        cout << "Do you want to open a file or input values?\n";
        cout << "1. Open File\n2. Input Values\nPlease Enter 1 or 2: ";
        cin.clear();
        cin.ignore();
        cin >> FileUserSelect;
    }

    //Asking user to if they want to save a file
    cout << "Do you want to open a file or input values?\n";
    cout << "1. Save File\n2. Don't Save File\nPlease Enter 1 or 2: ";
    cin >> FileSaveSelect;

    while(FileSaveSelect != "1" && FileSaveSelect != "2"){
        cout << "\nPlease enter a valid input.\n\n";
        cout << "Do you want to open a file or input values?\n";
        cout << "1. Open File\n2. Input Values\nPlease Enter 1 or 2: ";
        cin.clear();
        cin.ignore();
        cin >> FileSaveSelect;
    }
    if(FileSaveSelect == "1") {
        bool FileNameGood = true;
        File_IO_Mode += 1;
        do{
            cout << "\nWhat do you want to name your file?\n\n";
            cout << "Must be under 64 characters and not contain * . \" / \\ [ ] : ; | = ,\n";
            cin >> FileName;
            if(FileName.length() > 64){
                FileNameGood = false;
            }
            else if (!FileName.find_first_of("*.\"/\\[]:;|=,")){
                FileNameGood = false;
            }
            else{
                FileNameGood = true;
            }
            }while(!FileNameGood);

    }

    switch (FileUserSelect.at(0)) {
        case '1': {
            File_IO_Mode+= 1;
            cout << "What is the name of the file you're trying to open?\n";
            cin >> User_Input;
            ReadWriteFromFile(User_Input,FileName,File_IO_Mode, JustSomeDubs);
            break;
        }
        case '2': {
            cout << "Enter 1st value: ";
            cin >> User_Input;
            while(CheckForGarbage(User_Input)){
                cout << "Please enter a valid Number.\n";
                cout << "Enter 1st value: ";
                cin >> User_Input;
            }
            JustSomeDubs[0] = stod(User_Input);

            cout << "Enter 2nd value: ";
            cin >> User_Input;
            while(CheckForGarbage(User_Input)){
                cout << "Please enter a valid Number.\n";
                cout << "Enter 2nd value: ";
                cin >> User_Input;
            }
            JustSomeDubs[1] = stod(User_Input);

            if(File_IO_Mode == 2){
                string JustTryingSomething = "Not_Used";
                ReadWriteFromFile(JustTryingSomething,FileName,File_IO_Mode,JustSomeDubs);
            }
            else {
                SwapNumbers(JustSomeDubs);
            }

            break;

            //Default Case to catch cosmic ray interference or incredibly gifted users
            default:
                cout << "I really don't know how you got in here but this is awkward....\n";
                exit(1);

        }
    }

    system("pause");
}

void SplittingData (string UserInput, double UserString[]){
    string delimiter = " ";
    size_t pos = 0;
    string FoundNum;
    int i = 0;

    while ((pos = UserInput.find(delimiter)) != std::string::npos) {
        FoundNum = UserInput.substr(0, pos);
        UserString[i] = stod(FoundNum);
        UserInput.erase(0, pos + delimiter.length());
        i++;
    }

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


void SwapNumbers(double NumbersToSwap[]) {
    //swapping using third variable
    double temp = NumbersToSwap[0];
    NumbersToSwap[0] = NumbersToSwap[1];
    NumbersToSwap[1] = temp;
    cout << "Values after the first swap are:\n" << endl;
    cout << "x: " << NumbersToSwap[0] << " y: " << NumbersToSwap[1] << endl;

    // swapping without third variable
    NumbersToSwap[0] = NumbersToSwap[0] + NumbersToSwap[1];
    NumbersToSwap[1] = NumbersToSwap[0] - NumbersToSwap[1];
    NumbersToSwap[0] = NumbersToSwap[0] - NumbersToSwap[1];
    cout << "Values after the second swap are:\n";
    cout << "x: " << NumbersToSwap[0] << " y: " << NumbersToSwap[1] << endl;

    // swapping another way without another variable
    NumbersToSwap[0] = NumbersToSwap[0] * NumbersToSwap[1];
    NumbersToSwap[1] = NumbersToSwap[0] / NumbersToSwap[1];
    NumbersToSwap[0] = NumbersToSwap[0] / NumbersToSwap[1];
    cout << "Values after the third swap are:\n";
    cout << "x: " << NumbersToSwap[0] << " y: " << NumbersToSwap[1] << endl;
}

string ReadWriteFromFile (string InFileName, string OutFileName, int Mode, double UserInputData[]){
    string ZeData;
    double ZeDubs[2];
    ifstream Input;
    ofstream Output;
    switch (Mode){
        case 1: {
                Input.open(InFileName);
                if(Input.is_open()){
                    while(getline(Input,ZeData)){
                         SplittingData(ZeData, ZeDubs);
                        cout << "Values before swapping are:\n";
                        cout << "x: " << ZeDubs[0] << " y: " << ZeDubs[1] << endl;
                        SwapNumbers(ZeDubs);
                    }
                    break;
                }
        }
        case 2: {
            Output.open(OutFileName);
            //Since I only allow for one data entry in the user input I can get away with this
            if(Output.is_open()){
                SwapNumbers(UserInputData);
                Output << UserInputData[0] << " " << UserInputData[1] << endl;
            }
            break;
        }
        case 3:{
            Output.open(OutFileName);
            Input.open(InFileName);
            if(Input.is_open() && Output.is_open()){
                while(getline(Input,ZeData)){
                    SplittingData(ZeData, ZeDubs);
                    cout << "Values before swapping are:\n";
                    cout << "x: " << ZeDubs[0] << " y: " << ZeDubs[1] << endl;
                    SwapNumbers(ZeDubs);
                    Output << ZeDubs[0] << " " << ZeDubs[1] << endl;
                }
            }
            break;
        }
        default: {
            cout << "I really don't know how you got in here but this is awkward....\n";
            exit(1);
        }
    }
    Input.close();
    Output.close();
}