/*
 * Time.cpp
 *
 *  Created on: Apr. 19, 2024
 *      Author: juan
 */

#include "Time.hpp"

Time::Time(string _nome, int _vitorias, int _empates, int _derrotas, int _golsMarcados, int _golsSofridos) {
	//TODO
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

void Time::setGolsSofridos(int golSofridos) {
	this->golsSofridos = golsSofridos;
}

const string& Time::getNome() const {
	return nome;
}

void Time::setNome(const string &nome) {
	this->nome = nome;
}

int Time::getVitorias() const {
	return vitorias;
}

void Time::setVitorias(int vitorias) {
	this->vitorias = vitorias;
}

int Time::calcularPontos(){
	//TODO
}

int Time::calcularSaldoGols(){
	//TODO
}

void Time::atualizar(int gols1,int gols2){
	//TODO
}

Time::~Time() {
	// TODO Auto-generated destructor stub
}

