#include "vertice.h"
#include <iostream>

using namespace std;

Vertice::Vertice(int new_id) {
	this->id = new_id;
}

void Vertice::push_back(Vertice* v) {
	adjacentes.push_back(v);
}

int Vertice::grau() {
	return adjacentes.size();
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

void Vertice::imprime() {
	cout << "["<< id <<"]";
	for (Vertice* v: adjacentes)
		cout <<" -> "<< v->id;

	cout << endl;
}