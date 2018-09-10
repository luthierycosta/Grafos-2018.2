#include "lerArquivo.h"
#include "grafo.h"
#include "coefAglomeracao.h"

using namespace std;

int main() {
	
	Grafo g1 = lerArquivo();
	imprimeGrafo(g1);
	imprimeGrau(g1);
	coefAglomeracao(g1);

	return 0;
}