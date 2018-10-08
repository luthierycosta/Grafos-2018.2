#include "../headers/grafo.h"
#include "../headers/disciplina.h"
#include <algorithm>
#include <exception>
#include <iterator>
#include <iostream>
#include <string>

using namespace std;

Grafo::Grafo(){}

void Grafo::addVertice(string nome, int creditos, int dificuldade, int posicao) {
	if (!existeVertice(nome))
		vertices.push_back(Vertice(nome, creditos, dificuldade, posicao));
	else
		cout << "Vértice ["<< nome <<"] já existe no grafo.";
}

bool Grafo::existeVertice(string nome) {

	vector<Vertice>::iterator it;
	for (it = vertices.begin(); it != vertices.end(); it++)
		if((*it).id == nome)
			return true;

	return false;
}

Vertice& Grafo::getVertice(string nome) {
	
	vector<Vertice>::iterator it;
	for (it = vertices.begin(); it != vertices.end(); it++)
		if((*it).id == nome)
			return *it;

	throw "Argumento invalido."; 
}

void Grafo::addAresta(string id_a, string id_b) {

	if (!existeAresta(id_a, id_b)) {
		Vertice* v1 = &getVertice(id_a);
		Vertice* v2 = &getVertice(id_b);
		v1->push_back(v2);

	} else
		cout << "Aresta ("<< id_a <<", "<< id_b << ") já existe." << endl;
}

void Grafo::removeAresta(string id_a, string id_b) {

	if (existeAresta(id_a, id_b)) {
		Vertice* v1 = &getVertice(id_a);
		Vertice* v2 = &getVertice(id_b);
		v1->removeAresta(v2);
	
	} else
		cout << "Aresta ("<< id_a <<", "<< id_b << ") não existe." << endl;
}

bool Grafo::existeAresta(string id_a, string id_b) {
	Vertice* v1 = &getVertice(id_a);
	Vertice* v2 = &getVertice(id_b);

	return (v1->existeAresta(v2));
}

int Grafo::grau() {
	int res = 0;
	for (Vertice& v: vertices)
		res = max(res, v.grau());

	return res;
}

Grafo Grafo::inverso() {
	Grafo grafoInverso;

	for(Vertice& v: this->vertices)
		grafoInverso.addVertice(v.id.getNome(), v.id.getCreditos(), v.id.getDificuldade(), v.id.getPosicao());

	for(Vertice& v: this->vertices)
		for(Vertice* w: v.adjacentes)
			grafoInverso.addAresta(w->id.getNome(), v.id.getNome());

	return grafoInverso;

}

ostream& operator <<(ostream& os, const Grafo& grafo) {
	os << "\nGRAFO:\n";
	for(const Vertice v: grafo.vertices)
		os << v;

	os << endl;
	return os;
}
