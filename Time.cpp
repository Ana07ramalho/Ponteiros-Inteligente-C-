#include "Time.hpp"

#include <iostream>
#include <string>

using namespace std;

Time::Time(string nome, int golsMarcados, int golsSofridos) {
    this->nome = nome;
    this->golsMarcados = golsMarcados;
    this->golsSofridos = golsSofridos;
    this->vitorias = 0;
    this->empates = 0;
    this->derrotas = 0;
};

Time::Time() {
    this->nome = "";
    this->golsMarcados = 0;
    this->golsSofridos = 0;
    this->vitorias = 0;
    this->empates = 0;
    this->derrotas = 0;
};

void Time::imprime() const {
    std::cout << nome << "\t" << calcularPontos() << "\t" << (vitorias + empates + derrotas) << "\t" << vitorias << "\t" << empates << "\t" << derrotas << "\t" << golsMarcados << "\t" << golsSofridos << "\t" << calcularSaldoGols() << std::endl;
};

int Time::getDerrotas() const {
    return derrotas;
};

int Time::getVitorias() const {
    return vitorias;
};

void Time::setDerrotas(int derrotas) {
    this->derrotas = derrotas;
};

int Time::getEmpates() const {
    return empates;
};

void Time::setEmpates(int empates) {
    this->empates = empates;
};

int Time::getGolsMarcados() const {
    return golsMarcados;
};

void Time::setGolsMarcados(int golsMarcados) {
    this->golsMarcados = golsMarcados;
};

int Time::getGolsSofridos() const {
    return golsSofridos;
};

std::string Time::getNome() const {
    return nome;
};

void Time::setVitorias(int vitorias) {
    this->vitorias = vitorias;
};

int Time::calcularPontos() const {
    return (vitorias * 3 + empates);
};

int Time::calcularSaldoGols() const {
    return (this->golsMarcados - this->golsSofridos);
};


Time::~Time() {
    // Destrutor vazio, pois não há nada a liberar
};
