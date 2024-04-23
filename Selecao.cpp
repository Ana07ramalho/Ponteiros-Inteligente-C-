#include "Selecao.hpp"

Selecao::Selecao(std::string nome, int golsMarcados, int golsSofridos) : Time(nome, golsMarcados, golsSofridos) {
}

Selecao::~Selecao() {
    // Destrutor vazio, pois não há nada a liberar
}
