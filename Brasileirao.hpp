#ifndef BRASILEIRAO_HPP
#define BRASILEIRAO_HPP


#include <iostream>
#include <vector>

#include "Competicao.hpp"
#include "Time.hpp"
#include "Clube.hpp"

using namespace std;

class Brasileirao : public Competicao {

    protected:

    vector<shared_ptr<Clube>> clubes;

public:

    Brasileirao();
    virtual ~Brasileirao();

    void procurarInsertarTime(string nome, string cidade, int gol1, int gol2); 

    void atualizarTimes(int gols1, int gols2);

    virtual void lerTimes() override;

    virtual void melhor() override;

    virtual void ordenarTimes() override;

    virtual void imprimirTabela() override;

};

#endif /* BRASILEIRAO_HPP */