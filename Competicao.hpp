/*
 * Competicao.h
 *
 *  Created on: Apr. 19, 2024
 *      Author: juan
 */

#ifndef COMPETICAO_HPP_
#define COMPETICAO_HPP_

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include "Time.hpp"


using namespace std;

class Competicao : public Time{
	vector<shared_ptr<Time>> times;

public:

	Competicao();
	Competicao(string nome, int vitorias, int empates, int derrotas, int golsMarcados, int golsSofridos);
	virtual ~Competicao();

	const vector<shared_ptr<Time> >& getTimes() const;

	void setTimes(const vector<shared_ptr<Time> > &times);

	int addTime(shared_ptr<Time> &time);

	vector<shared_ptr<Time>>::iterator   procurarTime(string t);

	const shared_ptr<Time> & procurarInsertarTime(shared_ptr<Time> &time);

	void atualizarTimes(shared_ptr<Time> &time1, shared_ptr<Time> &time2, int gols1, int gols2);

	void ordenarTimes();

	virtual void melhor();

	virtual void imprimirTabela();

	virtual void lerTimes(shared_ptr<Time> &time1, shared_ptr<Time> &time2, int &gols1, int &gols2) = 0;

	//TODO pure virtual methods para ler os dados dos times, e outro para  mostrar o melhor
};

#endif /* COMPETICAO_H_ */