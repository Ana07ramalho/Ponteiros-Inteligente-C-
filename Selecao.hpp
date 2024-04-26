#ifndef SELECAO_HPP
#define SELECAO_HPP

#include <string>
#include "Time.hpp"

using namespace std;

class Selecao : public Time {

public:
    Selecao(string nome, int golsMarcados, int golsSofridos);
    ~Selecao(); // Destrutor

    void atualizarTime(int gols1, int gols2) override;

};

#endif /* SELECAO_HPP */
