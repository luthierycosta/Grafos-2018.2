#include "vertice.h"
#include <iostream>

using namespace std;

Vertice::Vertice(int new_id) {
	this->id = new_id;
}

void Vertice::push_back(int v) {
	adjacentes.push_back(v);
}

int Vertice::grau() {
	return adjacentes.size();
}

bool Vertice::existeAresta(int v) {
	for (int adj: adjacentes)
		if (adj == v)
			return true;

	return false;
}

bool Vertice::conectado() {
	return (adjacentes.size() != 0);
}

void Vertice::imprime() {
	cout << "["<< id <<"]";
	for (int v: adjacentes)
		cout <<" -> "<< v;

	cout << endl;
}