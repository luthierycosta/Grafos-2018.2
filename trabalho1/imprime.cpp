#include "imprime.h"

void imprimeGrau(Grafo& grafo) {
	for (unsigned int i = 1; i <= grafo.size()-1; i++)
		cout << "Vértice "<< i <<" tem grau "<< grafo[i].size() << endl;
}

void imprimeGrafo(Grafo& grafo) {
	for (unsigned int i = 1; i <= grafo.size()-1; i++) {
		
		cout <<"["<< i <<"]";
		for(int j: grafo[i])
			cout <<" -> {"<< j <<"}";
		
		cout << endl;
	}
}