#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

#include "Indice.hpp"

using namespace std;

int qtdPalavras = 0;
vector<std::string> palavrasOrdenadas;

vector<Indice> extracaoDePalavras(string str) {

    vector<Indice> palavras;

    string word = "";
    bool adiciona;

    for (auto x : str){

        if (x == ' '){

            adiciona = true;

            if(word != ""){
                qtdPalavras++;
            }

            if(word.size() >= 3){

                if(palavras.size() == 0){

                    palavras.push_back(Indice(word));
                    palavrasOrdenadas.push_back(word);

                } else {

                    int size = palavras.size();

                    for(int i = 0; i < size; i++){
                        if(word == palavras[i]._palavra){
                            palavras[i]._qtd++;
                            adiciona = false;
                            break;
                        }
                    }

                    if(adiciona){
                        palavras.push_back(Indice(word));
                        palavrasOrdenadas.push_back(word);
                    }
                }    
            }

            word = "";

        } else {

            word = word + x;

        }
    }

    if(word.size() >= 3){

        adiciona = true;

        int size = palavras.size();

        for(int i = 0; i < size; i++){
            if(word == palavras[i]._palavra){
                palavras[i]._qtd++;
                adiciona = false;
                break;
            }
        }

        if(adiciona){
            palavras.push_back(Indice(word));
            palavrasOrdenadas.push_back(word);
        }
    }

    return palavras;

}

int main(){

    //Pegar todo texto
    //Separar o texto em palvras, e incrementar qtd de palavras (splits de espaco e enter)
    //Adicionar palavras num vector (se repetido, incrementa no qtd do indice; caso nao repita, criar novo indice)
    //Printar cada elemento junto com sua quantidade e razao

    std::string texto;
    std::string aux;
    vector<Indice> palavras;

    for(int i = 0; i < 5; i++){
        std::getline(std::cin, aux);
        texto = texto + " " + aux;

    }

    palavras = extracaoDePalavras(texto);
    std::sort(palavrasOrdenadas.begin(), palavrasOrdenadas.end());

    int size = palavras.size();

    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(palavrasOrdenadas[i] == palavras[j]._palavra){
                float razao = ((float)palavras[j]._qtd / (float)qtdPalavras);
                std::cout << palavras[j]._palavra << " " << palavras[j]._qtd << " " << std::setprecision(2) << std::fixed << razao << std::endl;
            }
        }
    }

    return 0;
}