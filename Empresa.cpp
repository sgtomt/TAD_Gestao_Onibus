#include "Empresa.hpp"
#include <algorithm>

using namespace std;

Empresa::Empresa()
{
    quantidade_onibus = 0;
    ponteiro_onibus = std::vector<Onibus *>(20, nullptr);
}

Onibus *Empresa::adicionar_onibus(string placa, int lotacao_maxima)
{
    Onibus *procura_placa = busca_onibus(placa);

    if (procura_placa == nullptr)
    {
        Onibus *onibus = new Onibus(placa, lotacao_maxima);
        ponteiro_onibus.push_back(onibus);
    }

    return procura_placa;
}

Onibus *Empresa::busca_onibus(string placa)
{
    auto retorno = std::find_if(ponteiro_onibus.begin(), ponteiro_onibus.end(),
                                [placa](Onibus *o)
                                {
                                    return o != nullptr && o->placa == placa;
                                });

    if (retorno == ponteiro_onibus.end())
        return nullptr;

    return *retorno;
}

void Empresa::imprimir_estado()
{
    for (Onibus *o : ponteiro_onibus)
    {
        if (o != nullptr)
            o->imprimir_estado();
    }
}