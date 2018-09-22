#include "grafo.h"
#include "vertice.h"

using namespace std;

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