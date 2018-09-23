#include "../headers/vertice.h"
#include <iostream>

using namespace std;

Vertice::Vertice(int new_id) {
	this->id = new_id;
}

void Vertice::push_back(Vertice* v) {
	adjacentes.push_back(v);
}

bool Vertice::existeAresta(Vertice* v) {
	for (Vertice* adj: adjacentes)
		if (adj->id == v->id)
			return true;

	return false;
}

bool Vertice::conectado() {
	return (adjacentes.size() != 0);
}

int Vertice::grau() {
	return adjacentes.size();
}

double Vertice::coefAglomeracao() {

	int n_adj = this->grau();

	if (n_adj <= 1)
		return 0.0;
	else {
		double triangulos = 0;
		for (int i = 0; i < n_adj; i++) {
			for (int j = i+1; j < n_adj; j++) {
				if(adjacentes[i]->existeAresta(adjacentes[j]))
					triangulos++;
			}
		}
		return (2*triangulos / (n_adj*(n_adj-1)));
	}
}

void Vertice::imprime() {
	cout << "["<< id <<"]";
	for (Vertice* v: adjacentes)
		cout <<" -> "<< v->id;

	cout << endl;
}