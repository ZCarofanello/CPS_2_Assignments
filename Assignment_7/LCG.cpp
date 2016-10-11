//
// Created by Zack on 9/29/2016.
//

#include "LCG.h"
#include <cmath>

LCG::LCG(int Seed, int Multiplier, int Increment, int Modulus) {
    seed = Seed;
    multiplier = Multiplier;
    increment = Increment;
    modulus = Modulus;
}
/*
LCG::LCG(int Seed, int Multiplier) {
    seed = Seed;
    multiplier = Multiplier;
    increment = 0;//something
    modulus = 0; //something
}
*/

LCG::~LCG() {}

int LCG::RandomNumber() {
    seed = FirstTerm() % modulus;
    return seed;
}

int LCG::FirstTerm() {
    return (multiplier * seed) + increment;
}