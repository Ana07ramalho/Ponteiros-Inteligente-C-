#ifndef ELIMINATORIA_HPP
#define ELIMINATORIA_HPP

#include <iostream>
#include <vector>
#include "Competicao.hpp"

using namespace std;

class Eliminatoria : public Competicao {
    vector<shared_ptr<Time>> selecoes;

public:
    Eliminatoria();
    ~Eliminatoria();

    void lerTimes(shared_ptr<Time>& time1, shared_ptr<Time>& time2, int& gols1, int& gols2) override;

    void imprimirTabela() override;

    virtual void melhor() override;
};

#endif /* ELIMINATORIA_HPP */