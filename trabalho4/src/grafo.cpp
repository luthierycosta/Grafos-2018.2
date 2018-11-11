#include "../headers/grafo.h"
#include <vector>
#include <exception>
#include <iostream>
#include <queue>
#include <functional>

using namespace std;

Grafo::Grafo(){}

Grafo::~Grafo() {
	for(Vertice* v: vertices) delete v;
}

void Grafo::addVertice(Vertice* v) {
	if (!existeVertice(v->id))
		vertices.push_back(v);
	else
		cout << "Vértice ["<< v->id <<"] já existe no grafo.";
}

bool Grafo::existeVertice(int id) {
	for (Vertice* v: vertices)
		if(v->id == id)
			return true;

	return false;
}

Vertice* Grafo::findVertice(int id) {
	for (Vertice* v: vertices)
		if(v->id == id)
			return v;

	throw "Argumento invalido."; 
}

bool Grafo::existeAresta(Vertice* v1, Vertice* v2) {
	return (v1->existeAresta(v2));
}

bool Grafo::existeAresta(int v1, int v2) {
	return existeAresta(findVertice(v1), findVertice(v2));
}

void Grafo::addAresta(Vertice* v1, Vertice* v2) {
	v1->push_back(v2);
	v2->push_back(v1);
}

void Grafo::addAresta(int v1, int v2) {
	return addAresta(findVertice(v1), findVertice(v2));
}

void Grafo::removeAresta(Vertice* v1, Vertice* v2) {
	if(existeAresta(v1, v2)) {
		v1->removeAresta(v2);
		v2->removeAresta(v1);
	}
	else cout << "Aresta ("<< v1->id <<", "<< v2->id << ") não existe." << endl;
}

void Grafo::removeAresta(int v1, int v2) {
	return removeAresta(findVertice(v1), findVertice(v2));
}

void Grafo::bfs(Vertice* inicial, function<void (Vertice*)> foo) {

	vector<bool> visitados(vertices.size());		// cria vetor de visitados com |V| espaços
	queue<Vertice*> fila;							// cria fila

	for(Vertice* v: vertices)
		visitados[v->id] = false;				// todos começam com "não visitado"

	visitados[inicial->id] = true;
	fila.push(inicial);								// começa pelo vértice especificado

	while (!fila.empty()) {
		Vertice* v = fila.front();					// visita e depois remove o primeiro da fila
		foo(v);										// processa segundo a função especificada no argumento
		fila.pop();
		
		for(Vertice* w: v->adjacentes) {			// coloca todos seus adjacentes não visitados na fila
			if (!visitados[w->id]) {
				visitados[w->id] = true;
				fila.push(w);
			}
		}
	}
}

void Grafo::bfs(function<void (Vertice*)> foo) {	// não especificando o vértice inicial, ele usa o primeiro
	return bfs(vertices[0], foo);
}

void Grafo::dfs(Vertice* inicial, function<void (Vertice*)> foo) {
	vector<bool> visitados(vertices.size());		// cria vetor de visitados com |V| espaços
	for(Vertice* v: vertices)
		visitados[v->id] = false;				// todos começam com "não visitado"

	dfsAux(inicial, visitados, foo);
}

void Grafo::dfs(function<void (Vertice*)> foo) {	// não especificando o vértice inicial, ele usa o primeiro
	return dfs(vertices[0], foo);
}

void Grafo::dfsAux(Vertice* v, vector<bool>& visitados, function<void (Vertice*)> foo) {
	visitados[v->id] = true;
	foo(v);

	for(Vertice* w: v->adjacentes)
		if(!visitados[w->id])
			dfsAux(w, visitados, foo);
}

ostream& operator <<(ostream& os, const Grafo& grafo) {
	os << "\nGRAFO:\n";
	for(Vertice* v: grafo.vertices)
		os << *v;

	os << endl;
	return os;
}
