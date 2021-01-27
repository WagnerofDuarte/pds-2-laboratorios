#ifndef FILAPRIORIDADE
#define FILAPRIORIDADE

#include <iostream>
#include <vector>

#include "No.hpp"

using namespace std;

class FilaPrioridade {

  public:

    FilaPrioridade();
    
    void inserir(int prioridade, int dado);
    
    int remover();

    int estaVazio();
    
    int getTamanho();
    
    int getMeio();
    
    int getUltimo();
    
    void furaFila(int dado);

    void print();

  private:

    vector<No> fila; /// Ponteiro para o primeiro elemento da lista (as vezes chamado de cabeça) 
	  int tamanho;
};

#endif