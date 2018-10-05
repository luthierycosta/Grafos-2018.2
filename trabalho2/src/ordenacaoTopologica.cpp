#include "../headers/grafo.h"
#include "../headers/vertice.h"
#include <deque>
#include <map>
#include <string>

using namespace std;

void ordenacaoTopologicaAux(Vertice& v, map<string,bool>& visitados, deque<Vertice>& fila_ordenacao) {

	visitados[v.id.getNome()] = true;

	for(Vertice* v2: v.adjacentes)
		if (!visitados[v2->id.getNome()])
			ordenacaoTopologicaAux(*v2, visitados, fila_ordenacao);

	fila_ordenacao.push_front(v);
}

deque<Vertice> ordenacaoTopologica(Grafo& grafo) {
	
	map<string, bool> visitados;
	deque<Vertice> fila_ordenacao;

	for(Vertice& v: grafo.vertices)
		visitados[v.id.getNome()] = false;

	for(Vertice& v: grafo.vertices)
		if (!visitados[v.id.getNome()])
			ordenacaoTopologicaAux(v, visitados, fila_ordenacao);

	return fila_ordenacao;
}

