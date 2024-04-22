/*
 * Competicao.cpp
 *
 *  Created on: Apr. 19, 2024
 *      Author: juan
 */

#include "Competicao.hpp"

#include <iostream>
#include <vector>

using namespace std;


Competicao::Competicao() {
	// TODO Auto-generated constructor stub

};

Competicao::~Competicao() {
	// TODO Auto-generated destructor stub
};

int Competicao::addTime(shared_ptr<Time> &time){
	times.push_back(time);
	return times.size()-1;
};


void Competicao::ordenarTimes(){
	//TODO
};

vector<shared_ptr<Time>>::iterator  Competicao::procurarTime(string  t){

	for (auto it = times.begin(); it != times.end(); it++) {
		if ((*it)->getNome() == t) {
			return it;
		}
	}
	return times.end();

};

const shared_ptr<Time>&  Competicao::procurarInsertarTime(shared_ptr<Time> &t){
	
	auto it = procurarTime(t->getNome());
	if (it == times.end()) {
		addTime(t);
		return times.back();
	}
	return *it;
	
};



void Competicao::atualizarTimes(shared_ptr<Time> &time1, shared_ptr<Time> &time2, int gols1, int gols2){
	
	time1->atualizar(gols1, gols2);
	time2->atualizar(gols2, gols1);
};


void Competicao::imprimirTabela(){
	printf("                TIME");
	printf("\t P\t J\t V\t E\t D\t GP\t GC\t SG\n");

	for (unsigned int i = 0; i < times.size(); i++) {
		times[i]->imprime();
	}

	printf("\n");
};

const vector<shared_ptr<Time> >& Competicao::getTimes() const {
	return times;
};

void Competicao::setTimes(const vector<shared_ptr<Time> > &times) {
	
	this->times = times;
};

void lerTimes(shared_ptr<Time> &time1, shared_ptr<Time> &time2, int &gols1, int &gols2){

	string nome1, nome2;
	string cidade1, cidade2;
	int _gols1, _gols2;

	cin >> nome1 >> cidade1 >> _gols1;
	cin.ignore(); // Ignore the 'x' character
	cin >> _gols2 >> cidade2 >> nome2;

	time1 = make_shared<Time>(nome1, cidade1, _gols1, _gols2);
	time2 = make_shared<Time>(nome2, cidade2, _gols2, _gols1);

}


