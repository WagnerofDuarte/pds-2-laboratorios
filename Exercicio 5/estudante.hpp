#ifndef ESTUDANTE_H
#define ESTUDANTE_H

#include <string>

struct Estudante {
  std::string _nome;
  int _matricula;
  float _notas[5];
  
  float calcularRSG();
};

#endif