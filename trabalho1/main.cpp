#include "lerArquivo.h"
#include "grau.h"
#include "imprime.h"

using namespace std;

typedef vector<vector<int>> Grafo;

int main() {
	
	Grafo g1 = lerArquivo();
	imprimeGrafo(g1);
	imprimeGrau(g1);

	return 0;
}