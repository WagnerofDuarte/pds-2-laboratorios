#include "Jogador.hpp"
#include "Carta.hpp"

Jogador::Jogador () {
	this->_nomeJogador = "";
	this->_pontuacaoDasCartas = 0;
}

void Jogador::adicionaCarta (Carta carta){
	this->_cartas.push_back(carta);
}
	
string Jogador::getNomeJogador(){
	return this->_nomeJogador;
}

void Jogador::setNomeJogador(string nome){
	this->_nomeJogador = nome;
}

int Jogador::calcularPontuacao(){
	int total_pontos = 0;
	for (auto &c : this->_cartas) {
        total_pontos += c.getTotalPontos();
    }

	_pontuacaoDasCartas = total_pontos;

	return total_pontos;
}

int Jogador::getPontuacaoDasCartas(){
	return _pontuacaoDasCartas;
}

vector<Carta> Jogador::getCartas(){
	return this->_cartas;
}

void Jogador::setCartas(vector<Carta> cartas){
	this->_cartas = cartas;
}