#include "../headers/grafo.h"
#include "../headers/vertice.h"
#include <stack>
#include <map>
#include <string>

using namespace std;

void ordenacaoTopologicaAux(Vertice& v, map<string,bool>& visitados, stack<Vertice>& pilha_ordenacao) {

	visitados[v.id.getNome()] = true;

	for(Vertice* v2: v.adjacentes)
		if (!visitados[v2->id.getNome()])
			ordenacaoTopologicaAux(*v2, visitados, pilha_ordenacao);

	pilha_ordenacao.push(v);
}

stack<Vertice> ordenacaoTopologica(Grafo& grafo) {
	
	map<string, bool> visitados;
	stack<Vertice> pilha_ordenacao;

	for(Vertice& v: grafo.vertices)
		visitados[v.id.getNome()] = false;

	for(Vertice& v: grafo.vertices)
		if (!visitados[v.id.getNome()])
			ordenacaoTopologicaAux(v, visitados, pilha_ordenacao);

	return pilha_ordenacao;
}

