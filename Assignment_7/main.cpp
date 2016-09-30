#include <iostream>
#include "Blum_Blum_Shub.h"
int main() {


    for(int i = 1; i <= 30;i++){
        std::cout << Blum_Blum_Shub::Carmichael_F(i) << std::endl;
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}