#include "Brasileirao.hpp"
#include "Clube.hpp"
#include "Time.hpp"


Brasileirao::Brasileirao() {
    // TODO Auto-generated constructor stub
}

Brasileirao::~Brasileirao() {
    // TODO Auto-generated destructor stub
}

void Brasileirao::lerTimes(shared_ptr<Time> &time1, shared_ptr<Time> &time2, int &gols1, int &gols2) {
	
    string nome1, nome2;
	string cidade1, cidade2;
	int _gols1, _gols2;

	cin >> nome1 >> cidade1 >> _gols1;
	cin.ignore(); // Ignore the 'x' character
	cin >> _gols2 >> cidade2 >> nome2;

	time1 = make_shared<Time>(nome1, cidade1, _gols1, _gols2);
	time2 = make_shared<Time>(nome2, cidade2, _gols2, _gols1);
}

void Brasileirao::melhor() {

    int max = 0;
    shared_ptr<Clube> melhorTime; // Change to a pointer

    for (int i = 0; i < clubes.size(); i++) {
        if (clubes[i]->calcularPontos() > max) {
            max = clubes[i]->calcularPontos();
            melhorTime = clubes[i]; // Assign the pointer
        }
    }
    
    cout << "Melhor do Brasileirao" << endl << "Club:" << melhorTime->getNome() << ", Cidade" << melhorTime->getCidade() << endl; // Access the pointer using '->'
}