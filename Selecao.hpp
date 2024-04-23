#ifndef SELECAO_HPP_
#define SELECAO_HPP_

#include <string>
#include "Time.hpp"

class Selecao : public Time {

public:
    Selecao(std::string nome, int vitorias, int empates, int derrotas, int golsMarcados, int golsSofridos);
    ~Selecao(); // Destrutor

};

#endif /* SELECAO_HPP_ */
