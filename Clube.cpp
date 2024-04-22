#include "Clube.hpp"

using namespace std;

Clube::Clube(string nome, int vitorias, int empates, int derrotas, int golsMarcados, int golsSofridos, string cidade) : Time(nome, vitorias, empates, derrotas, golsMarcados, golsSofridos) {

    this -> cidade = cidade;

}

Clube::Clube() : Time() {

    this -> cidade = "";

}

string Clube::getCidade() {

    return cidade;

}

void Clube::setCidade(string cidade) {

    this -> cidade = cidade;

}

    vector<Clube> Clube::getClubes() {

    return clubes;

}

Clube::~Clube() {

    // TODO Auto-generated destructor stub
    
}