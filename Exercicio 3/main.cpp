#include <iostream>

#define SIZE 5

int main(){

    long array[SIZE] = {2, 4, 6, 8, 10};
    long value1=200000;
    long value2=200000;

    long * long_ptr = &value1;
    long * v_ptr = &array[0];
    
    //imprima o valor do objeto apontado por long_ptr

    std::cout << *long_ptr << " ";
    
    //Imprima o valor de value2

    std::cout << value2 << " ";
    
    //Imprima o endereço de value1

    std::cout << &value1 << " ";
    
    //Imprima o endereço armazenado em long_ptr

    std::cout << long_ptr << " ";
    
    //Imprima a comparação entre o endereço de value1 com o endereço armazenado em long_ptr

    std::cout << (&value1 == long_ptr) << " ";
        
    //imprimir os elementos do array values usando notação de array subscrito.

    for(int i = 0; i < SIZE; i++){
        std::cout << array[i] << " ";
    }
    
    //imprimir os elementos do array values usando notação de array ponteiro/deslocamento.

    for(int i = 0; i < SIZE; i++){
        std::cout << array[i] << " ";
    }
    
    //imprimir os elementos do array values usando notação de array ponteiro/deslocamento com o nome de array como o ponteiro.
    
    for(int i = 0; i < SIZE; i++){
        std::cout << array[i] << " ";
    }

    //imprimir os elementos do array values utilizando subscritos no ponteiro para o array.
    
    for(int i = 0; i < SIZE; i++){
        std::cout << array[i] << " ";
    }

    //imprimir o quinto elemento de values utilizando a notação de subscrito de array,
    
    std::cout << array[4] << " " << array[4] << " " << array[4] << " " << array[4] << " ";

    //a notação de ponteiro/deslocamento com o nome de array como o ponteiro, 
    
    v_ptr = v_ptr + 3;

    std::cout << v_ptr << " ";

    //a notação de subscrito de ponteiro,

    std::cout << *v_ptr << " ";
    
    //a notação de ponteiro/deslocamento.
    
    std::cout << v_ptr - 3 << " ";

    //imprimir a comparação entre o valor armazenado em (v_ptr-4) e values[0]

    std::cout << *(v_ptr - 3) << " ";

    return 0;
}