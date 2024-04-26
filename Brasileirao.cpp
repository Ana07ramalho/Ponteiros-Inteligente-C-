#include "Brasileirao.hpp"
#include "Competicao.hpp"
#include "Clube.hpp"
#include "Time.hpp"
#include <iomanip>
#include <iostream>

Brasileirao::Brasileirao() : clubes() {
}

Brasileirao::~Brasileirao() {
    // TODO Auto-generated destructor stub
}


void Brasileirao::ordenarTimes() {
    // Ordena o vetor clubes de acordo com os critérios
    std::sort(clubes.begin(), clubes.end(), [](const std::shared_ptr<Clube>& clube1, const std::shared_ptr<Clube>& clube2) {
        // Compara os pontos
        if (clube1->calcularPontos() != clube2->calcularPontos()) {
            return clube1->calcularPontos() > clube2->calcularPontos();
        }
        // Compara as vitórias
        if (clube1->getVitorias() != clube2->getVitorias()) {
            return clube1->getVitorias() > clube2->getVitorias();
        }
        // Compara o saldo de gols
        if (clube1->calcularSaldoGols() != clube2->calcularSaldoGols()) {
            return clube1->calcularSaldoGols() > clube2->calcularSaldoGols();
        }
        // Compara os gols marcados
        if (clube1->getGolsMarcados() != clube2->getGolsMarcados()) {
            return clube1->getGolsMarcados() > clube2->getGolsMarcados();
        }
        // Compara os nomes em ordem alfabética
        return clube1->getNome() < clube2->getNome();
    });

}

void Brasileirao::melhor() {
    cout << endl  << "Melhor do Brasileirao" << endl;
    cout << "Club: " << clubes.front()->getNome() << ", Cidade: " << clubes.front()->getCidade() << endl;

}

void Brasileirao::lerTimes() {

    string nome1, cidade1, nome2, cidade2;
    int gols1, gols2;

    cin >> nome1 >> cidade1 >> gols1;
    char x;
    cin >> x; // Ler o caractere 'x'
    cin >> gols2 >> nome2 >> cidade2;

    procurarInsertarTime(nome1, cidade1, gols1, gols2);
    procurarInsertarTime(nome2, cidade2, gols2, gols1);


}

void Brasileirao::procurarInsertarTime(string nome, string cidade, int gol1, int gol2) {
    bool encontrado = false;
    for (auto it = clubes.begin(); it != clubes.end(); ++it) {
        auto clube = *it;
        if (clube->getNome() == nome) {
            clube->atualizarTime(gol1, gol2);
            encontrado = true;
            break;
        }
    }
    if (!encontrado) {
        std::shared_ptr<Clube> novoClube(new Clube(nome, cidade, gol1, gol2));
        clubes.push_back(novoClube); // Adiciona no final do vetor
    }
}


void Brasileirao::imprimirTabela() {
    std::cout << "Brasileirao" << std::endl;
    std::cout << std::setw(20) << "TIME" << "\tP\tJ\tV\tE\tD\tGP\tGC\tSG" << std::endl;
    for (const auto& clube : clubes) {
        std::cout << std::setw(20) << clube->getNome() << "\t" << clube->calcularPontos() << "\t"
                  << (clube->getVitorias() + clube->getEmpates() + clube->getDerrotas()) << "\t"
                  << clube->getVitorias() << "\t" << clube->getEmpates() << "\t" << clube->getDerrotas() << "\t"
                  << clube->getGolsMarcados() << "\t" << clube->getGolsSofridos() << "\t" << clube->calcularSaldoGols() << std::endl;
    }

    cout << endl;
}
