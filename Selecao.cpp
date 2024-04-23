#include <string>
#include <vector>
#include "Selecao.hpp"

using namespace std;

Selecao::Selecao(string nome, int vitorias, int empates, int derrotas, int golsMarcados, int golsSofridos) : Time(nome, vitorias, empates, derrotas, golsMarcados, golsSofridos) {
}

vector<Time> Selecao::getSelecoes() {

    return selecoes;

}

Selecao::~Selecao() {

    //TODO Auto-generated destructor stub
    
}