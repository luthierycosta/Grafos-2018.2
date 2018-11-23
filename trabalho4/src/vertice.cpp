#include "../headers/vertice.h"
#include <iostream>
#include <algorithm>

using namespace std;

Vertice::Vertice(int id) {
	this->id = id;
}

void Vertice::push_back(Vertice* v) {
	adjacentes.push_back(v);
}

void Vertice::removeAresta(Vertice* v) {
	adjacentes.erase(remove(adjacentes.begin(), adjacentes.end(), v), adjacentes.end());
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

ostream& operator <<(ostream& os, const Vertice& v1) {
	os << "["<< v1.id <<"] - ";
	for (Vertice* v2: v1.adjacentes)
		os << v2->id << "; ";

	os << endl;
	return os;
}
