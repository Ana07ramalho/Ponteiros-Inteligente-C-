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

    void lerTimes(shared_ptr<Time> &time1, shared_ptr<Time> &time2, int &gols1, int &gols2);

    virtual void melhor() override;

    virtual void imprimirTabela() override;

};

#endif /* BRASILEIRAO_HPP */