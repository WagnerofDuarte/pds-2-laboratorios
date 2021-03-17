#include <iostream>
#include <algorithm>
#include <vector>

class IndiceNaoInicializado{};
class IndiceNegativo{};
class IndiceMaiorQueArranjo{};

template <class T, int N> class BoundedArray {
  public:
    void set(int index, T value) {
      buf[index] = value;
    }
    T get(int index) {
      return buf[index];
    }
  private:
    T buf[N];
};

template <class T> void testArray() {

  std::vector<int> posicoesUsadas;

  BoundedArray<T, 8> a;
  char action;
  while (std::cin >> action) {

    int index;
    std::cin >> index;

    //para aqui
    
    try {

      if (action == 's') {

          T value;
          std::cin >> value;

          //check aqui
          if(index > 7 ){

            throw IndiceMaiorQueArranjo();

          } else if(index < 0){

            throw IndiceNegativo();

          } else {

            a.set(index, value);
            posicoesUsadas.push_back(index);

          }

      } else if (action == 'g') {
        
        if(std::find(posicoesUsadas.begin(), posicoesUsadas.end(), index) != posicoesUsadas.end()){
            
          std::cout << a.get(index) << std::endl;

        } else if (index > 7 ){

            throw IndiceMaiorQueArranjo();

          } else if(index < 0){

            throw IndiceNegativo();

          } else {

          throw IndiceNaoInicializado();

        }
      }
      
    } catch (IndiceNaoInicializado a){
      std::cerr << "Erro: indice nao inicializado." << std::endl;
    } catch (IndiceNegativo a){
      std::cerr << "Erro: indice negativo." << std::endl;
    } catch (IndiceMaiorQueArranjo a){
      std::cerr << "Erro: indice maior que arranjo." << std::endl;
    }
  }
}

int main() {
  char type;
  std::cin >> type;
  switch(type) {
    case 'd':
      testArray<double>();
      break;
    case 'i':
      testArray<int>();
      break;
    case 's':
      testArray<std::string>();
      break;
  }
  return 0;
}