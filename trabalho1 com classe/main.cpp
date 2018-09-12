#include "grafo.h"
#include <iostream>

using namespace std;

int main() {

	Grafo grafo1;

	grafo1.lerArquivo();
	grafo1.imprime();
	cout << "\n";

	grafo1.imprimeGraus();
	cout << "\n";

	grafo1.imprimeCoefAglomeracao();

	return 0;
}