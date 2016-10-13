#include <iostream>

int main() {
    int n = 10000;
    int sumA = 0;
    int sumB = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= 10000; j++){
            sumA = sumA + j;
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            sumB = sumB + j;
        }
    }
    std::cout << sumA << std::endl;
    std::cout << sumB << std::endl;
    return 0;
}