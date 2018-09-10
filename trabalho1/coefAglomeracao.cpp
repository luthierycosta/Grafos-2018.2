#include "coefAglomeracao.h"

void coefAglomeracao(Grafo& grafo) {

	cout << "COEFICIENTES DE AGLOMERAÇÃO:" << endl;
	double soma_coefs = 0;

	for(int i = 1; i < (int)grafo.size(); i++) {						//i percorre cada vértice

		double triangulos = 0, coef_vertice = 0;

		double n_vertices = (int)grafo[i].size();

		for(int j = 0; j < n_vertices; j++) {
			for(int k = j+1; k < n_vertices; k++) {						// j e k percorrem a lista de adj. do vértice

				if (existeAresta(grafo, grafo[i][j], grafo[i][k]))
					triangulos++;
			}
		}
		if (n_vertices > 1)
			coef_vertice = (2*triangulos/(n_vertices*(n_vertices-1)));

		cout << "Coeficiente de aglomeração do vértice "<< i <<": "<< coef_vertice << endl;
		soma_coefs += coef_vertice;
	}

	double coef_grafo = soma_coefs / ((int)grafo.size()-1);
	cout << "Coeficiente médio de aglomeração do grafo: "<< coef_grafo << endl;
}
