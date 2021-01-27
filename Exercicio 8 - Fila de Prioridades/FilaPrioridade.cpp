#include "FilaPrioridade.hpp"

FilaPrioridade::FilaPrioridade(){
    
}

void FilaPrioridade::inserir(int prioridade, int dado){

    if(estaVazio() == 0){

        fila.push_back(No(prioridade, dado));

    } else {

        int i = 0;

        while(prioridade >= fila[i].getPrioridade() && i <= (getTamanho() - 1)){
            i++;
        }
        if(i == getTamanho()){
            fila.push_back(No(prioridade, dado));
        } else {
            fila.insert(fila.begin() + i, No(prioridade, dado));
        }
    }
}

int FilaPrioridade::remover(){

    int dado = fila[0].getDado();
    fila.erase(fila.begin());
    
    return dado;
}

int FilaPrioridade::estaVazio(){

    if(fila.empty()){
        return 0;
    }

    return 1;

}

int FilaPrioridade::getTamanho(){

    return fila.size();

}

int FilaPrioridade::getMeio(){

    int meio = (getTamanho())/2;
    
    return fila[meio].getDado();

}

int FilaPrioridade::getUltimo(){
    return fila[getTamanho() - 1].getDado();

}

void FilaPrioridade::furaFila(int dado){

    fila.insert(fila.begin(), No((fila[0].getPrioridade() - 1), dado));

}

void FilaPrioridade::print(){

    for(int i = 0; i < getTamanho(); i++){

        cout << fila[i].getDado() << " ";

    }

    cout << endl;

}
