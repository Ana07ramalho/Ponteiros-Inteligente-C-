#include <iostream>
#include <vector>
#include <memory>

#include "Brasileirao.hpp"
#include "Competicao.hpp"
#include "Eliminatoria.hpp"
#include "Time.hpp"
#include "Clube.hpp"

using namespace std;

int main() {

    vector<shared_ptr<Competicao>> competicoes;

    shared_ptr<Competicao> brasileiraoPtr = make_shared<Brasileirao>();
    shared_ptr<Competicao> eliminatoiraPtr = make_shared<Eliminatoria>();

    competicoes.push_back(brasileiraoPtr);
    competicoes.push_back(eliminatoiraPtr);

    competicoes.push_back(brasileiraoPtr);
    competicoes.push_back(eliminatoiraPtr);

    int njogos;
    shared_ptr<Time> time1, time2;
    int gols1, gols2;

    for(unsigned int j = 0; j < 2; j++) {

        cin >> njogos;

        for(auto i = 0; i < njogos; i++) {

            competicoes[j] -> lerTimes();

        }
        competicoes[j] -> ordenarTimes();
        competicoes[j] -> imprimirTabela();

    }

    for(unsigned int j = 0; j < 2; j++) {

        competicoes[j] -> melhor();

    }

    return 0;

}