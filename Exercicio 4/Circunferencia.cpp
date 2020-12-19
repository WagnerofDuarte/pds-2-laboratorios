#include "Circunferencia.hpp"

#include <cmath>

Circunferencia::Circunferencia(double xc, double yc, double raio){
    _xc = xc;
    _yc = yc;
    _raio = raio;

}

double Circunferencia::calcularArea(){
        return 3.14 * _raio * _raio;
}

bool Circunferencia::possuiIntersecao(Circunferencia* c){

    bool intercesao;

    double distanciasDosCentros = sqrt((_xc - c->_xc)*(_xc - c->_xc) + (_yc - c->_yc)*(_yc - c->_yc));

    if(distanciasDosCentros == _raio + c->_raio || distanciasDosCentros < _raio + c->_raio){
        intercesao = true;
    } else if(distanciasDosCentros > _raio + c->_raio)
        intercesao = false;
        
    return intercesao;
}