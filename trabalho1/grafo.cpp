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
