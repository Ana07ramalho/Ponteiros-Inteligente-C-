/*
 * Time.cpp
 *
 *  Created on: Apr. 19, 2024
 *      Author: juan
 */


#include <iostream>
#include "Time.hpp"

using namespace std;

Time::Time(string nome, int vitorias, int empates, int derrotas, int golsMarcados, int golsSofridos) {
    this->nome = nome;
    this->vitorias = vitorias;
    this->empates = empates;
    this->derrotas = derrotas;
    this->golsMarcados = golsMarcados;
    this->golsSofridos = golsSofridos;
	
}

Time::Time() {
    this->nome = "";
    this->vitorias = 0;
    this->empates = 0;
    this->derrotas = 0;
    this->golsMarcados = 0;
    this->golsSofridos = 0;
}

void Time::imprime(){

	printf("%20s\t%3d\t%3d\t%3d\t%3d\t%3d\t%3d\t%3d\t%3d\n",nome.c_str(), calcularPontos(), vitorias + empates + derrotas, vitorias, empates, derrotas, golsMarcados, golsSofridos, calcularSaldoGols());

}


int Time::getDerrotas() const {
	return derrotas;
}

void Time::setDerrotas(int derrotas) {
	this->derrotas = derrotas;
}

int Time::getEmpates() const {
	return empates;
}

void Time::setEmpates(int empates) {
	this->empates = empates;
}

int Time::getGolsMarcados() const {
	return golsMarcados;
}

void Time::setGolsMarcados(int golsMarcados) {
	this->golsMarcados = golsMarcados;
}

int Time::getGolsSofridos() const {
	return golsSofridos;
}

const string& Time::getNome(){
    return nome;
}

void Time::setVitorias(int vitorias) {
	this->vitorias = vitorias;
}

int Time::calcularPontos(){
	return (vitorias * 3 + empates);
}

int Time::calcularSaldoGols(){
	return (this->golsMarcados - this->golsSofridos);

}

void Time::atualizar(int gols1, int gols2){

    this->golsMarcados += gols1;
    this->golsSofridos += gols2;

    if (gols1 > gols2) {
        this->vitorias++;
    } else if (gols1 == gols2) {
        this->empates++;
    } else {
        this->derrotas++;
    }
	}

Time::~Time() {
	// TODO Auto-generated destructor stub
}

