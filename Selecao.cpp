#include "Selecao.hpp"

Selecao::Selecao(std::string nome, int golsMarcados, int golsSofridos) : Time(nome, golsMarcados, golsSofridos) {
}

Selecao::~Selecao() {
    // Destrutor vazio, pois não há nada a liberar
}

void Selecao::atualizarTime(int gols1, int gols2) {
    // Atualiza os gols marcados e sofridos
    golsMarcados += gols1;
    golsSofridos += gols2;

    // Atualiza o número de vitórias, empates e derrotas
    if (gols1 > gols2) {
        vitorias++;
    } else if (gols1 == gols2) {
        empates++;
    } else {
        derrotas++;
    }
}
