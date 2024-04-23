#ifndef SELECAO_HPP_
#define SELECAO_HPP_

#include <string>
#include "Time.hpp"

class Selecao : public Time {

public:
    Selecao(std::string nome, int golsMarcados, int golsSofridos);
    ~Selecao(); // Destrutor

};

#endif /* SELECAO_HPP_ */
