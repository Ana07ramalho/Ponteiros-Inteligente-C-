#ifndef ELIMINATORIA_HPP
#define ELIMINATORIA_HPP

#include <iostream>
#include <vector>

#include "Competicao.hpp"
#include "Time.hpp"

using namespace std;

class Eliminatoria : public Competicao {

    protected:

    shared_ptr<Time> Selecoes;

    public:

    Eliminatoria();
    ~Eliminatoria();

    Eliminatoria(string nome, int vitorias, int empates, int derrotas, int golsMarcados, int golsSofridos, shared_ptr<Time> Selecoes);

    void lerTimes(shared_ptr<Time> &time1, shared_ptr<Time> &time2, int &gols1, int &gols2);
      

};


#endif /* ELIMINATORIA_HPP */