#ifndef EMPRESA_HPP
#define EMPRESA_HPP
#include "Onibus.hpp"
#include <vector>

class Empresa
{
public:
    int quantidade_onibus;
    std::vector<Onibus *> ponteiro_onibus;

    Empresa();
    Onibus *adicionar_onibus(std::string, int);
    Onibus *busca_onibus(std::string);
    void imprimir_estado();
};

#endif