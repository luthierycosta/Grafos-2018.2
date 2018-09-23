#include "../headers/imprime.h"
#include "../headers/grafo.h"
#include "../headers/vertice.h"
#include <iostream>

using namespace std;

void imprimeGraus(Grafo& grafo) {

	cout << "GRAUS DOS VÉRTICES" << endl; 
	for(Vertice& v: grafo.vertices)
		cout << "Vértice "<< v.id <<" tem grau "<< v.grau() << endl;

	cout << "Grau do grafo: "<< grafo.grau() << endl;
}

void imprimeCoefAglomeracao(Grafo& grafo) {

	cout << "COEFICIENTES DE AGLOMERAÇÃO:" << endl;
	for (Vertice& v: grafo.vertices)
		cout << "Coeficiente de aglomeração do vértice "<< v.id <<": "<< v.coefAglomeracao() << endl;

	cout << "Coeficiente de aglomeração médio do grafo: "<< grafo.coefAglomeracao() << endl;
}

void imprimeCliques(Grafo& grafo) {}