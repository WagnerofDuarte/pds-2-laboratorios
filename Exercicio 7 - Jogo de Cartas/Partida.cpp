#include "Partida.hpp"
#include "Jogador.hpp"

Partida::Partida(int num_jogadores){
    this->_num_jogadores = num_jogadores;
}

//Partida::~Partida(){
    
//}
void Partida::addJogadorCarta(string nomeJogador, int numero_pontos_carta, string naipe, int novidade, int indiceJogador){

    if(novidade == 0){
        Jogador novoJogador;
        novoJogador.setNomeJogador(nomeJogador);
        this->setJogadores(novoJogador);
    }

    Carta novaCarta(numero_pontos_carta, naipe);
    this->_jogadores[indiceJogador].adicionaCarta(novaCarta);

}
	
int Partida::getNumJogadores(){

    return 0;

}

int Partida::getNumAtualJogadores(){

    return 0;

}

void Partida::setJogadores(Jogador jogadores){
    this->_jogadores.push_back(jogadores);
}

Jogador* Partida::getJogadores(){

    return nullptr;

}

Jogador Partida::getCampeao(){

    Jogador vencedor();
    int maiorPontuacao = 0;
    int indexDoVencedor;

    for(int i = 0; i < _num_jogadores; i++){
        if(maiorPontuacao < _jogadores[i].calcularPontuacao()){
            maiorPontuacao = _jogadores[i].calcularPontuacao();
            indexDoVencedor = i;
        }
    }

    return _jogadores[indexDoVencedor];
}

vector<Jogador> Partida::getJogadoresOrdenados(){

    vector<Jogador> jogadoresOrdenados;

    vector<int> somasDasPontuacoesIndividuais;
    for(int i = 0; i < this->_num_jogadores; i++){
        somasDasPontuacoesIndividuais.push_back(_jogadores[i].calcularPontuacao());
    }

    sort(somasDasPontuacoesIndividuais.begin(), somasDasPontuacoesIndividuais.end());

    /*for(int i = 0; i < _num_jogadores; i++){
        cout << somasDasPontuacoesIndividuais[i] << endl;
    }*/

    for(int i = 0; i < _num_jogadores; i++){
        for(int j = 0; j < _num_jogadores; j++){
            if(somasDasPontuacoesIndividuais[i] == _jogadores[j].calcularPontuacao()){
                jogadoresOrdenados.push_back(_jogadores[j]);
            }
        }
    }

    return jogadoresOrdenados;

}

void Partida::imprimeJogadoresOrdenados(vector<Jogador> jogadoresOrdenados){

    for(int i = 0; i < _num_jogadores; i++){
        cout << jogadoresOrdenados[i].getNomeJogador() << " " << jogadoresOrdenados[i].calcularPontuacao() << endl;
    }
    
}