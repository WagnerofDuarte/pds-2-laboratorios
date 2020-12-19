#ifndef CIRCUNFERENCIA_H
#define CIRCUNFERENCIA_H

struct Circunferencia {

    double _xc, _yc, _raio;

    Circunferencia(double xc, double yc, double raio);

    double calcularArea();
    bool possuiIntersecao(Circunferencia* c);

};

#endif