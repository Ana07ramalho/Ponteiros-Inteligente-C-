#ifndef CLUBE_HPP_
#define CLUBE_HPP_

#include <string>
#include <vector>

#include "Time.hpp"

using namespace std;


class Clube : protected Time {

    protected:

    string cidade;
    vector<Clube> clubes;

    public:

    Clube(string nome, int vitorias, int empates, int derrotas, int golsMarcados, int golsSofridos, string cidade) ;

    string getCidade();

    void setCidade(string cidade);

    vector<Clube> getClubes();

    void 

};

#endif /* CLUBE_HPP_ */