#include "Eliminatoria.hpp"
#include "Competicao.hpp"

#include <iostream>
#include <vector>

using namespace std;

Eliminatoria::Eliminatoria(){
    
    // TODO Auto-generated constructor stub
};

Eliminatoria::~Eliminatoria() {
    // TODO Auto-generated destructor stub
};

Eliminatoria::Eliminatoria(string nome, int vitorias, int empates, int derrotas, int golsMarcados, int golsSofridos, shared_ptr<Time> Selecoes) : Competicao(nome, vitorias, empates, derrotas, golsMarcados, golsSofridos){
    this->Selecoes = Selecoes;
};


void Eliminatoria::lerTimes(shared_ptr<Time> &time1, shared_ptr<Time> &time2, int &gols1, int &gols2) {
    string nome1, nome2;
    cin >> nome1;
    auto it1 = procurarTime(nome1);
    if (it1 == Selecoes.end()) {
        // Add time1 to Selecoes if not found
        Competicao::addTime(time1);
        // Retrieve the iterator again after adding to Selecoes
        it1 = procurarTime(nome1);
    }
    time1 = *it1;

    cin >> gols1;
    cin >> gols2;

    cin >> nome2;
    auto it2 = procurarTime(nome2);
    if (it2 == Selecoes.end()) {
        // Add time2 to Selecoes if not found
        Competicao::addTime(time2);
        // Retrieve the iterator again after adding to Selecoes
        it2 = procurarTime(nome2);
    }
    time2 = *it2;
}

