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

    shared_ptr<Competicao> brasileiraoPtr(new Brasileirao());
    shared_ptr<Competicao> eliminatoiraPtr(new Eliminatoria());

    competicoes.push_back(brasileiraoPtr);
    competicoes.push_back(eliminatoiraPtr);

    int njogos;
    shared_ptr<Time> time1, time2;
    int gols1, gols2;

    for(unsigned int j = 0; j < competicoes.size(); j++) {

        cin >> njogos;

        for(auto i = 0; i < njogos; i++) {

            competicoes[j] -> lerTimes(time1, time2, gols1, gols2);
            auto t1 = competicoes[j] -> procurarInsertarTime(time1);
            auto t2 = competicoes[j] -> procurarInsertarTime(time2);
            competicoes[j] -> atualizarTimes(t1, t2, gols1, gols2);

        }
        competicoes[j] -> ordenarTimes();
        competicoes[j] -> imprimirTabela();

    }

    for(unsigned int j = 0; j < competicoes.size(); j++) {

        competicoes[j] -> melhor();

    }

    return 0;

}