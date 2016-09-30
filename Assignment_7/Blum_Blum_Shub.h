//
// Created by Zack on 9/29/2016.
//

#ifndef ASSIGNMENT_7_BLUM_BLUM_SHUB_H
#define ASSIGNMENT_7_BLUM_BLUM_SHUB_H

#include <vector>

class Blum_Blum_Shub {
    Blum_Blum_Shub();
    ~Blum_Blum_Shub();

public:
    static int Carmichael_F (int n);

private:
    std::vector PrimeFactors(int);

    std::vector<int> Factors;


};


#endif //ASSIGNMENT_7_BLUM_BLUM_SHUB_H
