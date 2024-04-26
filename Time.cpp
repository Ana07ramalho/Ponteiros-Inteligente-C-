#include "Time.hpp"

#include <iostream>
#include <string>

using namespace std;

Time::Time(string nome, int golsMarcados, int golsSofridos) {
    this->nome = nome;
    this->golsMarcados = golsMarcados;
    this->golsSofridos = golsSofridos;

    if(golsMarcados > golsSofridos) {
        this->vitorias = 1;
        this->empates = 0;
        this->derrotas = 0;
    } else if(golsMarcados == golsSofridos) {
        this->vitorias = 0;
        this->empates = 1;
        this->derrotas = 0;
    } else {
        this->vitorias = 0;
        this->empates = 0;
        this->derrotas = 1;
    }

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
printf("%20s\t%3d\t%3d\t%3d\t%3d\t%3d\t%3d\t%3d\t%3d\n",nome.c_str(), calcularPontos(), vitorias + empates + derrotas, vitorias, empates, derrotas, golsMarcados, golsSofridos, calcularSaldoGols());
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
