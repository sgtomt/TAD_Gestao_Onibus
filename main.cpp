#include <iostream>
#include "Empresa.hpp"
#include "Onibus.hpp"

using namespace std;

int main()
{
    bool finaliza = false;
    Empresa *empresa = new Empresa();
    std::string placa = " ";
    std::string outra_placa = " ";
    int inteiro = 0;
    do
    {
        char opcao = ' ';
        cin >> opcao;

        switch (opcao)
        {
        case 'C':
        {
            cin >> placa >> inteiro;
            void *opcao_c = empresa->adicionar_onibus(placa, inteiro);
            if (opcao_c == nullptr)
            {
                cout << "novo onibus cadastrado" << endl;
            }
            else
                cout << "ERRO : onibus repetido" << endl;
            break;
        }
        case 'S':
        {
            cin >> placa >> inteiro;
            void *opcao_s = empresa->busca_onibus(placa);
            if (opcao_s == nullptr)
            {
                cout << "ERRO : onibus inexistente" << endl;
            }
            else
            {
                Onibus *o = static_cast<Onibus *>(opcao_s);
                bool subir = o->subir_passageiros(inteiro);
                if (subir)
                {
                    cout << "passageiros subiram com sucesso" << endl;
                }
                else
                    cout << "ERRO : onibus lotado" << endl;
            }
            break;
        }
        case 'D':
        {
            cin >> placa >> inteiro;
            void *opcao_s = empresa->busca_onibus(placa);
            if (opcao_s == nullptr)
            {
                cout << "ERRO : onibus inexistente" << endl;
            }
            else
            {
                Onibus *o = static_cast<Onibus *>(opcao_s);
                bool descer = o->descer_passageiros(inteiro);
                if (descer)
                {
                    cout << "passageiros desceram com sucesso" << endl;
                }
                else
                    cout << "ERRO : faltam passageiros" << endl;
            }
            break;
        }
        case 'T':
        {
            cin >> placa >> outra_placa >> inteiro;
            void *opcao_t1 = empresa->busca_onibus(placa);
            void *opcao_t2 = empresa->busca_onibus(outra_placa);
            if (opcao_t1 == nullptr || opcao_t2 == nullptr)
            {
                cout << "ERRO : onibus inexistente" << endl;
            }
            else
            {
                Onibus *o1 = static_cast<Onibus *>(opcao_t1);
                Onibus *o2 = static_cast<Onibus *>(opcao_t2);
                bool transferir = o1->transfere_passageiros(o2, inteiro);
                if (transferir)
                {
                    cout << "transferencia de passageiros efetuada" << endl;
                }
                else
                    cout << "ERRO : transferencia cancelada" << endl;
            }
            break;
        }
        case 'I':
        {
            empresa->imprimir_estado();
            break;
        }
        case 'F':
        {
            finaliza = true;
            break;
        }
        default:
            break;
        }
    } while (!finaliza);

    return 0;
};