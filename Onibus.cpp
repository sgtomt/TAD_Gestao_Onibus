#include "Onibus.hpp"
using namespace std;

Onibus::Onibus()
{
    this->placa = string();
    this->lotacao_atual = 0;
    this->lotacao_maxima = 0;
}

Onibus::Onibus(string placa, int lotacao_maxima)
{
    this->placa = placa;
    this->lotacao_maxima = lotacao_maxima;
}

bool Onibus::subir_passageiros(int numero_passageiros)
{
    bool retorno = true;
    if (this->lotacao_atual + numero_passageiros > lotacao_maxima)
        return false;

    this->lotacao_atual += numero_passageiros;

    return retorno;
}

bool Onibus::descer_passageiros(int numero_passageiros)
{
    bool retorno = true;
    if (this->lotacao_atual == 0)
        return false;

    if (this->lotacao_atual - numero_passageiros < 0)
        return false;

    this->lotacao_atual -= numero_passageiros;
    return retorno;
}

bool Onibus::transfere_passageiros(Onibus *destino, int numero_passageiros)
{
    if ((!this->descer_passageiros(numero_passageiros)) || (!destino->subir_passageiros(numero_passageiros)))
    {
        return false;
    }
    return true;
}

void Onibus::imprimir_estado()
{
    cout << this->placa << "(" << this->lotacao_atual << "/" << this->lotacao_maxima << ")" << endl;
}
