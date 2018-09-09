//#include "vertice.h"
#include "grafo.h"
#include <iostream>

using namespace std;

int main() {

	Grafo grafo1;
/*
	grafo1.addAresta(1, 2);
	grafo1.addAresta(1, 3);
	grafo1.addAresta(1, 4);
	grafo1.addAresta(3, 4);

	Vertice v1 = grafo1.getVertice(1);
	v1.imprime();

	if (grafo1.existeAresta(3, 4))
		cout << "IT FUNFS" << endl;
*/
	grafo1.lerArquivo();
	grafo1.imprime();
	grafo1.imprimeGraus();
	grafo1.coefAglomeracao();

	return 0;
}