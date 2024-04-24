#include "Eliminatoria.hpp"
#include "Time.hpp"
#include "Competicao.hpp"
#include <iomanip> // Include the <iomanip> header to access std::setw
#include <string>
#include <iostream>

using namespace std;

Eliminatoria::Eliminatoria() {
    // inicialize outros membros, se necessário
}


Eliminatoria::~Eliminatoria() {
    // Não é necessário implementar o destrutor, pois não há recursos a serem liberados explicitamente
};

void Eliminatoria::melhor() {
    shared_ptr<Time> melhorTime;

    int INT_MIN = 0;
    
    // Inicializa as variáveis de comparação
    int maxPontos = INT_MIN;
    int maxVitorias = INT_MIN;
    int maxSaldoGols = INT_MIN;
    int maxGolsPro = INT_MIN;
    string nomeAlfabetico;

    // Percorre todos os times para encontrar o melhor time
    for (const auto& time : selecoes) {
        if (time->calcularPontos() > maxPontos) {
            // Se o time tem mais pontos, atualiza o melhor time
            maxPontos = time->calcularPontos();
            maxVitorias = time->getVitorias();
            maxSaldoGols = time->calcularSaldoGols();
            maxGolsPro = time->getGolsMarcados();
            nomeAlfabetico = time->getNome();
            melhorTime = time;
        } else if (time->calcularPontos() == maxPontos) {
            // Se o time tem os mesmos pontos, considera os critérios de desempate
            if (time->getVitorias() > maxVitorias ||
                (time->getVitorias() == maxVitorias && time->calcularSaldoGols() > maxSaldoGols) ||
                (time->getVitorias() == maxVitorias && time->calcularSaldoGols() == maxSaldoGols && time->getGolsMarcados() > maxGolsPro) ||
                (time->getVitorias() == maxVitorias && time->calcularSaldoGols() == maxSaldoGols && time->getGolsMarcados() == maxGolsPro && time->getNome() < nomeAlfabetico)) {
                maxVitorias = time->getVitorias();
                maxSaldoGols = time->calcularSaldoGols();
                maxGolsPro = time->getGolsMarcados();
                nomeAlfabetico = time->getNome();
                melhorTime = time;
            }
        }
    }

    // Verifica se o melhor time foi encontrado e imprime suas informações
    if (melhorTime != nullptr) {
        cout << "Melhor da Eliminatoria" << endl
             << "Pais: " << melhorTime->getNome() << endl;
    } else {
        cout << "Nenhum time encontrado." << endl;
    }
};

void Eliminatoria::lerTimes(shared_ptr<Time>& time1, shared_ptr<Time>& time2, int& gols1, int& gols2) {
    string nome1, nome2;
    cin >> nome1;
    auto it1 = Competicao::procurarTime(nome1);
    if (it1 == getTimes().end()) {
        // Adiciona time1 às seleções se não encontrado
        time1 = make_shared<Time>(nome1, gols1, gols2); // Criar um novo time com valores padrão
        Competicao::addTime(time1);
        selecoes.push_back(time1); // Adiciona time1 à lista de seleções
    } else {
        time1 = *it1;
    }

    cin >> gols1 >> gols2;

    cin >> nome2;
    auto it2 = Competicao::procurarTime(nome2);
    if (it2 == getTimes().end()) {
        // Adiciona time2 às seleções se não encontrado
        time2 = make_shared<Time>(nome2, gols2, gols1); // Criar um novo time com valores padrão
        Competicao::addTime(time2);
        selecoes.push_back(time2); // Adiciona time2 à lista de seleções
    } else {
        time2 = *it2;
    }
}

void Eliminatoria::imprimirTabela() {
    std::cout << "Eliminatoria" << std::endl;
    std::cout << std::setw(20) << "TIME" << "\tP\tJ\tV\tE\tD\tGP\tGC\tSG" << std::endl;
    for (const auto& time : getTimes()) {
        std::cout << std::setw(20) << time->getNome() << "\t" << time->calcularPontos() << "\t"
                  << (time->getVitorias() + time->getEmpates() + time->getDerrotas()) << "\t"
                  << time->getVitorias() << "\t" << time->getEmpates() << "\t" << time->getDerrotas() << "\t"
                  << time->getGolsMarcados() << "\t" << time->getGolsSofridos() << "\t" << time->calcularSaldoGols() << std::endl;
    }
}



