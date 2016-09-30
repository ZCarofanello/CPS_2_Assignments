//
// Created by Zack on 9/29/2016.
//

#include "Blum_Blum_Shub.h"
#include <vector>
#include <cmath>

Blum_Blum_Shub::Blum_Blum_Shub() {

};

Blum_Blum_Shub::~Blum_Blum_Shub(){

};

int Blum_Blum_Shub::Carmichael_F(int n) {
    return 1 % n;
}

std::vector Blum_Blum_Shub::PrimeFactors(int number) {
    float j;
    if(number < 2)
        Factors.push_back(number);
    while(number % 2 == 0) {
        Factors.push_back(2);
        number = number / 2;
    }
    if (number % 2 == 0)
        //return false;
    j = sqrt(number); // Moving sqrt calculation out of the loop
    for(int i=3; i <=j ; i+=2){
        if(number % i == 0 )
            //return false;
}
//return true;
}