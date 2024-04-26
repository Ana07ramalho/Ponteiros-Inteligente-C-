#include "Clube.hpp"
#include "Time.hpp"

Clube::Clube(string nome, string cidade, int golsMarcados, int golsSofridos) : Time(nome, golsMarcados, golsSofridos) {
    this->cidade = cidade;
}

// Método para inicializar um objeto Clube com valores padrão
Clube::Clube() : Time() {
    this->cidade = "";
};

void Clube::atualizarTime(int gols1, int gols2) {
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
};  

string Clube::getCidade() const {
    return cidade;
};

void Clube::setCidade(string cidade) {
    this->cidade = cidade;
};

Clube::~Clube() {
    // Destrutor vazio, pois não há nada a liberar
};
