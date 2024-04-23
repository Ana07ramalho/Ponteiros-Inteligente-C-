#include "Selecao.hpp"

Selecao::Selecao(std::string nome, int vitorias, int empates, int derrotas, int golsMarcados, int golsSofridos) : Time(nome, vitorias, empates, derrotas, golsMarcados, golsSofridos) {
}

Selecao::~Selecao() {
    // Destrutor vazio, pois não há nada a liberar
}
