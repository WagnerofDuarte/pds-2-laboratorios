#include "estudante.hpp"

float Estudante::calcularRSG(){
  return((notas[0]+notas[1]+notas[2]+notas[3]+notas[4])/5);
}