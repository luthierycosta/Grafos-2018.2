#include "lerArquivo.h"
#include "grafo.h"
#include "imprime.h"

using namespace std;

int main() {
	
	Grafo g1 = lerArquivo();
	imprimeGrafo(g1);
	imprimeGrau(g1);

	return 0;
}