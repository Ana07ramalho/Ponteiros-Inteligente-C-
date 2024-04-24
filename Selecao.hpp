#ifndef SELECAO_HPP
#define SELECAO_HPP

#include <string>
#include "Time.hpp"

class Selecao : public Time {

public:
    Selecao(std::string nome, int golsMarcados, int golsSofridos);
    ~Selecao(); // Destrutor

};

#endif /* SELECAO_HPP */
