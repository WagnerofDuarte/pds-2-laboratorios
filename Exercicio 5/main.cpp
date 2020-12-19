#include "estudante.hpp"

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

vector<Estudante> melhorAluno(vector<Estudante> estudantes){

  Estudante melhor = estudantes[0];
  int count = (int) estudantes.size();
  int index = 0;

  for(int i = 0; i < count; i++){
    if(estudantes[i].calcularRSG() > melhor.calcularRSG()){
      //atualiza o melhor
      melhor = estudantes[i];
      index = i;
    } else if(estudantes[i].calcularRSG() == melhor.calcularRSG()){
      //mesmo estudante?
      if(melhor.nome == estudantes[i].nome){
        //sim, nada muda
        melhor = estudantes[i];
      } else {
        //nao, atualiza com o que tem menor matricula
        if(estudantes[i].matricula < melhor.matricula){
          melhor = estudantes[i];
          index = i;
        }
      }
    }
  }

  std::cout << melhor.matricula << " " << melhor.nome << " " << setprecision (2) << fixed << melhor.calcularRSG() << std::endl;

  estudantes.erase(estudantes.begin() + index);

  return estudantes;

}

int main() {

  vector<Estudante> estudantes;

  for(int i = 0; i < 10; i++){

    Estudante estudante;

    std::cin >> estudante.matricula >> estudante.nome >> estudante.notas[0] >> estudante.notas[1] >> estudante.notas[2] >> estudante.notas[3] >> estudante.notas[4];
    
    estudantes.push_back(estudante);
    
  }

  for(int i = 0; i < 3; i++){
    estudantes = melhorAluno(estudantes);
  }

  return 0;

}