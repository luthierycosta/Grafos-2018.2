//#include "vertice.h"
#include "grafo.h"
#include <iostream>

using namespace std;

void Grafo::coefAglomeracao() {

	double coef_medio;

	if((int)vertices.size() == 0)
		coef_medio = 0.0;
	else {
		
		double soma_coefs = 0;
		for(Vertice v: vertices) {
			
			double coef_vertice = 0, triangulos = 0;
	
			if (v.grau() > 1) {
				
				for(int i = 0; i < v.grau(); i++) {
					for(int j = i+1; j < v.grau(); j++) {				// i e j percorrem a lista de adj. do vértice
						if (existeAresta(v.adjascentes[i], v.adjascentes[j]))
							triangulos++;
					}
				}
				coef_vertice = (2*triangulos / (v.grau()*(v.grau()-1)));
			}
			cout << "Coef. aglomeração do vértice "<< v.id <<": "<< coef_vertice << endl;
			soma_coefs += coef_vertice;
		}
		coef_medio = soma_coefs/((int)vertices.size()-1);
	}
	cout << "Coef. aglomeração médio do grafo: "<< coef_medio << endl;
}
/*
double Vertice::coefAglomeracao() {

	int n_adj = this->grau();
	
	if (n_adj <= 1) {				// se o vértice tem 1 ou 0 adjascentes, não há triângulos possíveis
		return 0.0;
	} else {
	
		int triangulos = 0;
		for(int i = 0; i < n_adj; i++) {
			for(int j = i+1; j < n_adj; j++) {				// i e j percorrem a lista de adj. do vértice
				
				if (adjascentes[i].existeAresta(adjascentes[j]))
					triangulos++;
			}
		}
		return (2*triangulos/(n_adj*(n_adj-1)));
	}
}

*/
