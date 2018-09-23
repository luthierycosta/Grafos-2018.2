#include "../headers/grafo.h"
#include <algorithm>	// max
#include <exception>
#include <iterator>
#include <iostream>

using namespace std;

Grafo::Grafo(){}

Grafo::Grafo(int n) {
	for(int i = 1; i <= n; i++)
		addVertice(i);
}

void Grafo::addVertice(int id) {
	vertices.push_back(Vertice(id));
}

Vertice& Grafo::getVertice(int id) {
	
	vector<Vertice>::iterator it;
	for (it = vertices.begin(); it != vertices.end(); it++)
		if((*it).id == id)
			return *it;

	throw "Argumento invalido."; 
}

void Grafo::addAresta(int id_a, int id_b) {

	if (!existeAresta(id_a, id_b)) {
		Vertice* v1 = &getVertice(id_a);
		Vertice* v2 = &getVertice(id_b);
		v1->push_back(v2);
		v2->push_back(v1);

	} else {
		cout << "Aresta "<< id_a <<" - "<< id_b << "já existe." << endl;
	}
}

bool Grafo::existeAresta(int id_a, int id_b) {
	Vertice* v1 = &getVertice(id_a);
	Vertice* v2 = &getVertice(id_b);

	return (v1->existeAresta(v2));
}

bool Grafo::conectado() {
	for (Vertice& v: vertices)
		if (!v.conectado())
			return false;

	return true;
}

int Grafo::grau() {
	int res = 0;
	for (Vertice& v: vertices)
		res = max(res, v.grau());

	return res;
}

double Grafo::coefAglomeracao() {

	if(vertices.size() == 0)
		return 0.0;
	else {
		double soma_coefs = 0.0;
		for(Vertice& v: vertices) {
			soma_coefs += v.coefAglomeracao();
		}
		return soma_coefs/vertices.size();
	}
}

void Grafo::imprime() {
	cout << "\nGRAFO:\n";
	for(Vertice& v: vertices)
		v.imprime();

	cout << endl;
}