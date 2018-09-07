#include <iostream>			// cin e cout
#include <vector>
#include <algorithm>		// max	

using namespace std;

typedef vector<vector<int>> Grafo;

Grafo gerarGrafo() {
	// hard d++
}

int grau(Grafo& gr) {
	int res = 0;
	for (vector<int> vertice: gr)
		res = max(res, vertice.size());
	
	return res;
}

void printGrau(Grafo& gr) {
	for (i = 1; i <= gr.size(); i++)
		cout << "Vértice "<< i <<" tem grau "<< gr[i].size() << endl;
}

int main() {
	Grafo grafo1 = gerarGrafo();

	printGrau(grafo1);

	return 0;
}