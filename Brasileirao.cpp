#include "Brasileirao.hpp"
#include "Competicao.hpp"
#include "Clube.hpp"
#include "Time.hpp"
#include <iomanip>

Brasileirao::Brasileirao() {
    // TODO Auto-generated constructor stub
}

Brasileirao::~Brasileirao() {
    // TODO Auto-generated destructor stub
}


void Brasileirao::melhor() {
    shared_ptr<Clube> melhorTime;

    int intMin = 0;
    
    // Inicializa as variáveis de comparação
    int maxPontos = intMin;
    int maxVitorias = intMin;
    int maxSaldoGols = intMin;
    int maxGolsPro = intMin;
    string nomeAlfabetico;

    // Percorre todos os clubes para encontrar o melhor time
    for (const auto& clube : clubes) {
        if (clube->calcularPontos() > maxPontos) {
            // Se o time tem mais pontos, atualiza o melhor time
            maxPontos = clube->calcularPontos();
            maxVitorias = clube->getVitorias();
            maxSaldoGols = clube->calcularSaldoGols();
            maxGolsPro = clube->getGolsMarcados();
            nomeAlfabetico = clube->getNome();
            melhorTime = clube;
        } else if (clube->calcularPontos() == maxPontos) {
            // Se o time tem os mesmos pontos, considera os critérios de desempate
            if (clube->getVitorias() > maxVitorias ||
                (clube->getVitorias() == maxVitorias && clube->calcularSaldoGols() > maxSaldoGols) ||
                (clube->getVitorias() == maxVitorias && clube->calcularSaldoGols() == maxSaldoGols && clube->getGolsMarcados() > maxGolsPro) ||
                (clube->getVitorias() == maxVitorias && clube->calcularSaldoGols() == maxSaldoGols && clube->getGolsMarcados() == maxGolsPro && clube->getNome() < nomeAlfabetico)) {
                maxVitorias = clube->getVitorias();
                maxSaldoGols = clube->calcularSaldoGols();
                maxGolsPro = clube->getGolsMarcados();
                nomeAlfabetico = clube->getNome();
                melhorTime = clube;
            }
        }
    }

    // Verifica se o melhor time foi encontrado e imprime suas informações
    if (melhorTime != nullptr) {
        cout << "Melhor do Brasileirao" << endl
             << "Clube: " << melhorTime->getNome() << ", "
             << "Cidade: " << melhorTime->getCidade() << endl;
    } else {
        cout << "Nenhum time encontrado." << endl;
    }
}


 // Include the <iomanip> header to access std::setw

void Brasileirao::lerTimes(shared_ptr<Time> &time1, shared_ptr<Time> &time2, int &gols1, int &gols2) {
 
    string nome1, nome2;
    string cidade1, cidade2;
    int _gols1, _gols2;

    cin >> nome1 >> cidade1 >> _gols1;
    cin.ignore(); // Ignore the 'x' character
    cin >> _gols2 >> cidade2 >> nome2;

    time1 = make_shared<Clube>(nome1, cidade1, _gols1, _gols2);
    time2 = make_shared<Clube>(nome2, cidade2, _gols2, _gols1);
}

void Brasileirao::imprimirTabela() {
    std::cout << "Brasileirao" << std::endl;
    std::cout << std::setw(20) << "TIME" << "\tP\tJ\tV\tE\tD\tGP\tGC\tSG" << std::endl;
    for (const auto& time : getTimes()) {
        std::cout << std::setw(20) << time->getNome() << "\t" << time->calcularPontos() << "\t"
                  << (time->getVitorias() + time->getEmpates() + time->getDerrotas()) << "\t"
                  << time->getVitorias() << "\t" << time->getEmpates() << "\t" << time->getDerrotas() << "\t"
                  << time->getGolsMarcados() << "\t" << time->getGolsSofridos() << "\t" << time->calcularSaldoGols() << std::endl;
    }
}
