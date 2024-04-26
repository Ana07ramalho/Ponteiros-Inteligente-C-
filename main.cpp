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

    int njogos;

    for(unsigned int j = 0; j < 2; j++) {

        cin >> njogos;

        for(auto i = 0; i < njogos; i++) {

            competicoes[j] -> lerTimes();

        }
        competicoes[j] -> ordenarTimes();
        competicoes[j] -> imprimirTabela();

    }

    competicoes[0] -> melhor();
    cout << endl;
    competicoes[1] -> melhor();
    cout << endl;

    return 0;

}