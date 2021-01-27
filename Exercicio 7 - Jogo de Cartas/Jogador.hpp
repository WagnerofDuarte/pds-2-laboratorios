#ifndef JOGADOR
#define JOGADOR

#include <string>
#include <vector>
#include "Carta.hpp"

using namespace std;

class Jogador {
private:
	string _nomeJogador;
	vector<Carta> _cartas;
	int _pontuacaoDasCartas;

public:

	Jogador();
	void adicionaCarta (Carta carta);
	
	vector<Carta> getCartas();
	void setCartas(vector<Carta> cartas);
	
	string getNomeJogador();
	void setNomeJogador(string nome);

	int getPontuacaoDasCartas();
	
	int calcularPontuacao();
};

#endif
