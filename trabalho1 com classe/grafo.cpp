#include "grafo.h"
//#include "vertice.h"
#include <iostream>
#include <algorithm>	// max
#include <exception>
#include <iterator>

using namespace std;

Grafo::Grafo(){}

Grafo::Grafo(int qtd_vertices) {
	for(int i = 1; i <= qtd_vertices; i++)
		addVertice(i);
}

Grafo::~Grafo() {
	for (Vertice v: vertices)
		v.adjascentes.clear();
	
	//for (Vertice v: vertices) delete (v);
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
		(getVertice(id_a)).push_back(id_b);
		(getVertice(id_b)).push_back(id_a);
	}
}

bool Grafo::existeAresta(int id_a, int id_b) {
	
	if ((getVertice(id_a)).existeAresta(id_b))
		return true;
	else
		return false;
}

int Grafo::grau() {
	int res = 0;
	for (Vertice v: vertices)
		res = max(res, v.grau());

	return res;
}

bool Grafo::conectado() {
	for (Vertice v: vertices)
		if (!v.conectado())
			return false;

	return true;
}

void Grafo::imprime() {
	cout << "\nGrafo:\n";
	for(Vertice v: vertices)
		v.imprime();

	cout << endl;
}

void Grafo::imprimeGraus() {
	for(Vertice v: vertices)
		cout << "Vértice "<< v.id <<" tem grau "<< v.grau() << endl;

	cout << "Grau do grafo: "<< this->grau() << endl;
}