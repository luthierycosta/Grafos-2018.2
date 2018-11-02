#include "../headers/grafo.h"
#include "../headers/vertice.h"
#include "../headers/lerArquivo.h"
#include <iostream>

using namespace std;

int main() {

	Grafo grafo1;

	lerArquivo(grafo1, "arquivos/karate.txt");
	cout << grafo1 << endl;

	cout << "GRAUS DOS VÉRTICES" << endl; 
	for(Vertice& v: grafo1.vertices)
		cout << "Vértice "<< v.getId() <<" tem grau "<< v.grau() << endl;

	cout << "Grau do grafo: "<< grafo1.grau() << "\n\n";

	cout << "COEFICIENTES DE AGLOMERAÇÃO:" << endl;
	for (Vertice& v: grafo1.vertices)
		cout << "Coeficiente de aglomeração do vértice "<< v.getId() <<": "<< v.coefAglomeracao() << endl;

	cout << "Coeficiente de aglomeração médio do grafo: "<< grafo1.coefAglomeracao() << endl;


	return 0;
}