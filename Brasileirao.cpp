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
    sort(clubes.begin(), clubes.end(), [](const shared_ptr<Clube>& clube1, const shared_ptr<Clube>& clube2) {
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
    cout << "Melhor do Brasileirao:" << endl;
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
        shared_ptr<Clube> novoClube(new Clube(nome, cidade, gol1, gol2));
        clubes.push_back(novoClube); // Adiciona no final do vetor
    }
}


/*void Brasileirao::imprimirTabela() {
    cout << "Brasileirao" << endl;
    cout << setw(15) << "TIME" << "\t" << "P\tJ\tV\tE\tD\tGP\tGC\tSG" << endl;
    for (const auto& clube : clubes) {
        cout << setw(15) << clube->getNome() << "\t" << setw(2) << clube->calcularPontos() << "\t"
                  << setw(2) << (clube->getVitorias() + clube->getEmpates() + clube->getDerrotas()) << "\t"
                  << setw(2) << clube->getVitorias() << "\t" << setw(2) << clube->getEmpates() << "\t" 
                  << setw(2) << clube->getDerrotas() << "\t"
                  << setw(2) << clube->getGolsMarcados() << "\t" << setw(2) << clube->getGolsSofridos() << "\t" 
                  << setw(2) << clube->calcularSaldoGols() << endl;
    }
    cout << endl;
}*/

void Brasileirao::imprimirTabela(){
    printf("Brasileirao:\n");
	printf("                TIME");
	printf("\t P\t J\t V\t E\t D\t GP\t GC\t SG\n");

	for (unsigned int i = 0; i < clubes.size(); i++) {
		clubes[i]->imprime();
	}

	printf("\n");
}

