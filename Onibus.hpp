#ifndef ONIBUS_HPP
#define ONIBUS_HPP

#include <iostream>

class Onibus
{
public:
    std::string placa;
    int lotacao_maxima;
    int lotacao_atual;

    Onibus();
    Onibus(std::string, int);
    bool subir_passageiros(int);
    bool descer_passageiros(int);
    bool transfere_passageiros(Onibus *, int);
    void imprimir_estado();
};
#endif