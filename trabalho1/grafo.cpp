#include "grafo.h"

int grau(Grafo& grafo) {
	int res = 0;
	for (vector<int> vertice: grafo)
		res = max(res, (int)vertice.size());
	
	return res;
}

void addAresta(Grafo& grafo, int vertice1, int vertice2) {
	grafo[vertice1].push_back(vertice2);
	grafo[vertice2].push_back(vertice1);
}

bool existeAresta(Grafo& grafo, int vertice1, int vertice2) {
	
	if ((int)grafo.size() <= vertice1 ||
		(int)grafo.size() <= vertice2  )
		return false;

	else for(int adj: grafo[vertice1]) {
		if (adj == vertice2)
			return true;
	}
	return false;
}


void imprimeGrau(Grafo& grafo) {
	cout << "GRAUS DOS VÉRTICES" << endl; 
	for (unsigned int i = 1; i <= grafo.size()-1; i++)
		cout << "Vértice "<< i <<" tem grau "<< grafo[i].size() << endl;
}

void imprimeGrafo(Grafo& grafo) {
	cout << "\nGRAFO:\n";
	for (unsigned int i = 1; i <= grafo.size()-1; i++) {
		
		cout <<"["<< i <<"]";
		for(int j: grafo[i])
			cout <<" -> "<< j;
		
		cout << endl;
	}
}
