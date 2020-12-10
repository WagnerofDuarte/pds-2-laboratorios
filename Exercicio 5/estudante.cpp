#include "Estudante.hpp"

Estudante:: Estudante(std::string nome, int matricula, float notas[]){
  _nome = nome;
  _matricula = matricula;
  _notas = notas;
}

float Estudante::calcularRSG() {
    return ((_notas[0]+_notas[1]+_notas[2]+_notas[3]+_notas[4])/5);
}

