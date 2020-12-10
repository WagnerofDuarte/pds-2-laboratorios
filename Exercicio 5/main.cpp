#include <iostream>
#include <cstdlib>

#include "Estudante.hpp"

int main() {
    
    //float vector[5] = {1,2,3,4,5};
    
    Estudante* estudante = new Estudante("teste", 2020, {1,2,3,4,5});
    
    std::cout << estudante->calcularRSG() << std::endl;
    
    delete estudante;
    
    return 0;
}