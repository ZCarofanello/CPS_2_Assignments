//
// Created by Zack on 9/29/2016.
//

#ifndef ASSIGNMENT_7_LCG_H
#define ASSIGNMENT_7_LCG_H

#include <vector>
#include <stdint.h>

class LCG {
public:
    LCG();
    //LCG();
    ~LCG();
    void SetValues(int Seed, int multiplier, int increment, int modulus);
    int RandomNumber();

private:
    int modulus, seed, increment, multiplier;

    int BitShifitingMod (void);
    int FirstTerm (void);

};


#endif //ASSIGNMENT_7_BLUM_BLUM_SHUB_H
