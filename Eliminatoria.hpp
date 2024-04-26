#ifndef ELIMINATORIA_HPP
#define ELIMINATORIA_HPP

#include <iostream>
#include <vector>
#include "Competicao.hpp"
#include "Selecao.hpp"

using namespace std;

class Eliminatoria : public Competicao {
    vector<shared_ptr<Selecao>> selecoes;

public:
    Eliminatoria();
    ~Eliminatoria();

    void lerTimes() override;
    void procurarInsertarTime(string nome, int gol1, int gol2); 
    void imprimirTabela() override;

    void ordenarTimes() override;

    virtual void melhor() override;
};

#endif /* ELIMINATORIA_HPP */