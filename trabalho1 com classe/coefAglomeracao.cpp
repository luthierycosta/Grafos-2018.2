#include "grafo.h"
#include <iostream>

using namespace std;

void Grafo::coefAglomeracao() {

	cout << "COEFICIENTES DE AGLOMERAÇÃO:" << endl;
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
			cout << "Coeficiente de aglomeração do vértice "<< v.id <<": "<< coef_vertice << endl;
			soma_coefs += coef_vertice;
		}
		coef_medio = soma_coefs/((int)vertices.size());
	}
	cout << "Coeficiente de aglomeração médio do grafo: "<< coef_medio << endl;
}
