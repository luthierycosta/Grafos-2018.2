#include "../headers/grafo.h"
#include "../headers/disciplina.h"
#include <vector>
#include <algorithm>
#include <exception>
#include <iterator>
#include <iostream>
#include <string>
#include <queue>
#include <functional>

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
		if((*it).getNome() == nome)
			return true;

	return false;
}

Vertice& Grafo::getVertice(string nome) {
	
	vector<Vertice>::iterator it;
	for (it = vertices.begin(); it != vertices.end(); it++)
		if((*it).getNome() == nome)
			return *it;

	throw "Argumento invalido."; 
}

void Grafo::addAresta(string nome_a, string nome_b) {

	if (!existeAresta(nome_a, nome_b)) {
		Vertice* v1 = &getVertice(nome_a);
		Vertice* v2 = &getVertice(nome_b);
		v1->push_back(v2);

	} else
		cout << "Aresta ("<< nome_a <<", "<< nome_b << ") já existe." << endl;
}

void Grafo::removeAresta(string nome_a, string nome_b) {

	if (existeAresta(nome_a, nome_b)) {
		Vertice* v1 = &getVertice(nome_a);
		Vertice* v2 = &getVertice(nome_b);
		v1->removeAresta(v2);
	
	} else
		cout << "Aresta ("<< nome_a <<", "<< nome_b << ") não existe." << endl;
}

bool Grafo::existeAresta(string nome_a, string nome_b) {
	Vertice* v1 = &getVertice(nome_a);
	Vertice* v2 = &getVertice(nome_b);

	return (v1->existeAresta(v2));
}

int Grafo::grau() {
	int res = 0;
	for (Vertice& v: vertices)
		res = max(res, v.grau());

	return res;
}

void Grafo::bfs(Vertice& inicial, function<void (Vertice&)> foo) {

	vector<bool> visitados(vertices.size());		// cria vetor de visitados com |V| espaços
	queue<Vertice> fila;							// cria fila

	for(Vertice& v: vertices)
		visitados[v.getId()] = false;				// todos começam com "não visitado"

	visitados[inicial.getId()] = true;
	fila.push(inicial);						// começa pelo vértice especificado

	while (!fila.empty()) {
		Vertice v = fila.front();					// visita e depois remove o primeiro da fila
		foo(v);										// processa segundo a função especificada no argumento
		fila.pop();
		
		for(Vertice* w: v.adjacentes) {				// coloca todos seus adjacentes não visitados na fila
			if (!visitados[w->getId()]) {
				visitados[w->getId()] = true;
				fila.push(*w);
			}
		}
	}
}

void Grafo::bfs(function<void (Vertice&)> foo) {	// não especificando o vértice inicial, ele usa o primeiro
	bfs(vertices[0], foo);
}

void Grafo::dfs(Vertice& inicial, function<void (Vertice&)> foo) {

	vector<bool> visitados(vertices.size());		// cria vetor de visitados com |V| espaços
	for(Vertice& v: vertices)
		visitados[v.getId()] = false;				// todos começam com "não visitado"

	dfsAux(inicial, visitados, foo);
}

void Grafo::dfs(function<void (Vertice&)> foo) {	// não especificando o vértice inicial, ele usa o primeiro
	dfs(vertices[0], foo);
}

void Grafo::dfsAux(Vertice& v, vector<bool>& visitados, function<void (Vertice&)> foo) {

	visitados[v.getId()] = true;
	foo(v);

	for(Vertice* w: v.adjacentes)
		if(!visitados[w->getId()])
			dfsAux(*w, visitados, foo);
}

Grafo Grafo::inverso() {
	Grafo grafoInverso;

	for(Vertice& v: this->vertices)
		grafoInverso.addVertice(v.getNome(), v.getCreditos(), v.getDificuldade(), v.getId());

	for(Vertice& v: this->vertices)
		for(Vertice* w: v.adjacentes)
			grafoInverso.addAresta(w->getNome(), v.getNome());

	return grafoInverso;
}

ostream& operator <<(ostream& os, const Grafo& grafo) {
	os << "\nGRAFO:\n";
	for(const Vertice v: grafo.vertices)
		os << v;

	os << endl;
	return os;
}
