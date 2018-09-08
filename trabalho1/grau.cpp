#include "grau.h"

int grau(Grafo& grafo) {
	int res = 0;
	for (vector<int> vertice: grafo)
		res = max(res, (int)vertice.size());
	
	return res;
}