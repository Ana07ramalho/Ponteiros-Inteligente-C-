#include "Clube.hpp"

using namespace std;

Clube::Clube(string nome, int vitorias, int empates, int derrotas, int golsMarcados, int golsSofridos, string cidade) : Time(nome, vitorias, empates, derrotas, golsMarcados, golsSofridos) {

    this -> cidade = cidade;

}

string Clube::getCidade() {

    return cidade;

}

void Clube::setCidade(string cidade) {

    this -> cidade = cidade;

}

vector<Time> Clube::getClubes() {

    return clubes;

}