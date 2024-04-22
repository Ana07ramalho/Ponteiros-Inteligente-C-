#ifndef TIMES_HPP_
#define TIMES_HPP_

#include <string>

using namespace std;


class Time{

    protected:

    int derrotas;
    int empates;
    string nome;
    int golsMarcados;
    int golsSofridos;
    int vitorias;


    public:

    Time(string nome, int vitorias, int empates, int derrotas, int golsMarcados, int golsSofridos);
    Time();

    void imprime();

    int getDerrotas() const;

    void setDerrotas(int derrotas);

    int getEmpates() const;

    void setEmpates(int empates);

    int getGolsMarcados() const;

    void setGolsMarcados(int golsMarcados);

    int getGolsSofridos() const;

    void setGolsSofridos(int golSofridos);

    const string& getNome();

    void setNome(const string &nome);

    int getVitorias() const;

    void setVitorias(int vitorias);

    int calcularPontos();

    int calcularSaldoGols();

    void atualizar(int gols1,int gols2);

    ~Time();

};

#endif /* TIMES_HPP_ */