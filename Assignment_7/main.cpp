#include <iostream>
#include "LCG.h"
#include <vector>

int main() {
    std::vector<int> RandomInts;
    int tests = 1000;

    int gentest = 2;
    for(int i = 0; i < 50; i++) {
        LCG Testing(i,i,i+1,100);
        int sum = 0;
        double avg;
        for (int j = 0; j < tests; j++) {
            int k = Testing.RandomNumber();
            RandomInts.push_back(k);
            sum += k;
        }
        avg = sum / tests;
        gentest = avg;
        std::cout << avg << std::endl;
    }
    return 0;
}