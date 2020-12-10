#include <iostream>

int main() {
    int x;
    std::cin >> x;
    
    int i = 1;
    
    while(i < x){
        for(int j = 0; j < i; j++){
            std::cout <<"*";
        }
        std::cout << "\n";
        i++;
    }
    
    while(i >= 1){
        for(int j = i; j >= 1; j--){
            std::cout <<"*";
        }
        std::cout << "\n";
        i--;
    }
    
    return 0;
}