#include "../headers/vertice.h"
#include "../headers/disciplina.h"
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

Vertice::Vertice(string nome, int creditos, int dificuldade, int id) {
	this->id = id;
	this->label = Disciplina(nome, creditos, dificuldade);
}

int Vertice::getId() {
	return id;
}

string Vertice::getNome() {
	return label.getNome();
}

int Vertice::getCreditos() {
	return label.getCreditos();
}

int Vertice::getDificuldade() {
	return label.getDificuldade();
}

int Vertice::peso() {
	return label.peso();
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

ostream& operator <<(ostream& os, const Vertice& vert) {
	os << "["<< vert.label <<"] - ";
	for (Vertice* v: vert.adjacentes)
		os << v->label << "; ";

	os << endl;
	return os;
}
