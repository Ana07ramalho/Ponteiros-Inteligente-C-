#ifndef CLUBE_HPP_
#define CLUBE_HPP_

#include <string>
#include <vector>

#include "Time.hpp"

using namespace std;


class Clube : public Time {

    protected:

    string cidade;
    vector<Time> clubes;

    public:

    Clube(string nome, int vitorias, int empates, int derrotas, int golsMarcados, int golsSofridos, string cidade) ;
    Clube();

    string getCidade();

    void setCidade(string cidade);

    vector<Clube> getClubes();

    ~Clube();

};

#endif /* CLUBE_HPP_ */