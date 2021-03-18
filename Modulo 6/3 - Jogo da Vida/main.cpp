#include <iostream>
#include <chrono>
#include <thread>

#include "game_of_life.h"

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using namespace std::literals::chrono_literals;

void Print(const GameOfLife& g) {
  cout << "  "; 
  for (int i = 0; i < g.columns(); ++i) {
    cout << "- "; 
  }
  cout << endl;
  for (int i = 0; i < g.lines(); ++i) {
    cout << "| ";
    for (int j = 0; j < g.columns(); ++j) {
      if (g.alive(i, j)) {
        cout << "* "; 
      } else {
        cout << "  ";
      }
    }
    cout << "|" << endl;
  }
  cout << "  "; 
  for (int i = 0; i < g.columns(); ++i) {
    cout << "- "; 
  }
  cout << endl;
}

#include <memory>
#include <string>

using namespace std;

int main() {
  // Lê os dados.
  int linhas, colunas;
  int iterations;
  cin >> iterations;
  int line, column;
  cin >> linhas >> colunas;
  GameOfLife g(linhas, colunas);
  while (cin >> line) {

    cin >> column;

    try{

      if(line < 0 || line >= linhas || column < 0 || column >= colunas){
        throw GameOfLife::InvalidCellException();
      } else {
        g.Enliven(line, column);
      }

    } catch (GameOfLife::InvalidCellException e) {

      cerr << "As coordenadas [" << line << ", " << column << "] não são de uma célula válida" << endl;
      return 1;

    }
  }

  Print(g);
    
  // Executa o número esperado de iterações.
  while (iterations > 0) {
    g++;
    Print(g);
    std::this_thread::sleep_for(10ms);
    iterations--;
  }
}