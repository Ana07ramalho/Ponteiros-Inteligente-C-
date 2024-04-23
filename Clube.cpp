#include "Clube.hpp"
#include "Time.hpp"

Clube::Clube(string nome, string cidade, int golsMarcados, int golsSofridos) : Time(nome, golsMarcados, golsSofridos) {
    this->cidade = cidade;
}

// Método para inicializar um objeto Clube com valores padrão
Clube::Clube() : Time() {
    this->cidade = "";
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
