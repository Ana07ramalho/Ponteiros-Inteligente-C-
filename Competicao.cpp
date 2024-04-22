/*
 * Competicao.cpp
 *
 *  Created on: Apr. 19, 2024
 *      Author: juan
 */

#include "Competicao.hpp"


Competicao::Competicao() {
	// TODO Auto-generated constructor stub

}

Competicao::~Competicao() {
	// TODO Auto-generated destructor stub
}

int Competicao::addTime(shared_ptr<Time> &time){
	times.push_back(time);
	return times.size()-1;
}


void Competicao::ordenarTimes(){
	//TODO
}

vector<shared_ptr<Time>>::iterator  Competicao::procurarTime(string  t){
	//TODO
}

const shared_ptr<Time>&  Competicao::procurarInsertarTime(shared_ptr<Time> &t){
	//TODO
}



void Competicao::atualizarTimes(shared_ptr<Time> &time1, shared_ptr<Time> &time2, int gols1, int gols2){
	//TODO
}


void Competicao::imprimirTabela(){
	printf("                TIME");
	printf("\t P\t J\t V\t E\t D\t GP\t GC\t SG\n");

	for (unsigned int i = 0; i < times.size(); i++) {
		times[i]->imprime();
	}

	printf("\n");
}

const vector<shared_ptr<Time> >& Competicao::getTimes() const {
	return times;
}

void Competicao::setTimes(const vector<shared_ptr<Time> > &times) {
	this->times = times;
}


