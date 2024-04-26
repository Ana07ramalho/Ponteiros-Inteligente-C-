/*
 * Competicao.h
 *
 *  Created on: Apr. 19, 2024
 *      Author: juan
 */

#ifndef COMPETICAO_HPP
#define COMPETICAO_HPP

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include "Time.hpp"


using namespace std;

class Competicao {
	vector<shared_ptr<Time>> times;

public:

	Competicao();
	Competicao(string nome, int vitorias, int empates, int derrotas, int golsMarcados, int golsSofridos);
	virtual ~Competicao();

	const vector<shared_ptr<Time> >& getTimes() const;

	void setTimes(const vector<shared_ptr<Time> > &times);

	int addTime(shared_ptr<Time> &time);  

	virtual void melhor() = 0;

	virtual void imprimirTabela() =0;

	virtual void lerTimes() = 0;

	virtual void ordenarTimes() = 0;


	//TODO pure virtual methods para ler os dados dos times, e outro para  mostrar o melhor
};

#endif /* COMPETICAO_H */