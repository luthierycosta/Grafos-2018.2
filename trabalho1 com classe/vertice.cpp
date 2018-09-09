#include "vertice.h"
#include <iostream>

using namespace std;

Vertice::Vertice(int new_id) {
	this->id = new_id;
}

void Vertice::push_back(int v) {
	adjascentes.push_back(v);
}

int Vertice::grau() {
	return adjascentes.size();
}

bool Vertice::existeAresta(int v) {
	for (int adj: adjascentes)
		if (adj == v)
			return true;

	return false;
}

bool Vertice::conectado() {
	return (adjascentes.size() != 0);
}

void Vertice::imprime() {
	cout << "["<< id <<"]";
	for (int v: adjascentes)
		cout <<" -> "<< v;

	cout << endl;
}