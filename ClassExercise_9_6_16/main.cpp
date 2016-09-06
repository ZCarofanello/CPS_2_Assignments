#include <iostream>

int Factorial (int N);
int SquareNumbers(int Number);

int main() {
    SquareNumbers(6);
    system("pause");
    return 0;
}

int Factorial (int N){

}

int SquareNumbers (int Number){
    int result;
    if (Number == 1){
        return 1;
    }
    result = SquareNumbers(Number - 1) + 2*(Number - 1) + 1;
    std::cout << "The Square of " << Number << " is " << result << std::endl;
    return result;
}