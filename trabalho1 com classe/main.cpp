#include "grafo.h"
#include "vertice.h"
#include "imprime.h"
#include <iostream>

using namespace std;

int main() {

	Grafo grafo1;

	grafo1.lerArquivo("arquivos/karate.txt");
	grafo1.imprime();
	cout << "\n";

	imprimeGraus(grafo1);
	cout << "\n";

	imprimeCoefAglomeracao(grafo1);

	return 0;
}