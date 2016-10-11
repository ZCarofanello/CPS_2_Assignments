//
// Created by Zack on 9/29/2016.
//

#include "LCG.h"
#include <cmath>

LCG::LCG() {
    seed = 0;
    multiplier = 0;
    increment = 0;
    modulus = 0;
}

LCG::~LCG() {}

void LCG::SetValues(int Seed, int Multiplier, int Increment, int Modulus) {
    seed = Seed;
    multiplier = Multiplier;
    increment = Increment;
    modulus = Modulus;
}

int LCG::RandomNumber() {
    seed = FirstTerm() % modulus;
    return seed;
}

int LCG::FirstTerm() {
    return (multiplier * seed) + increment;
}