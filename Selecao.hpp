#ifndef SELECAO_HPP_
#define SELECAO_HPP_

#include <string>
#include <vector>

#include "Time.hpp"

using namespace std;


class Selecao : protected Time {

    protected:

    vector<Time> selecoes;

    public:

    Selecao(string nome, int vitorias, int empates, int derrotas, int golsMarcados, int golsSofridos) ;

    vector<Time> getSelecoes();
    
    ~Selecao();
    
};

#endif/* SELECAO_HPP_ */