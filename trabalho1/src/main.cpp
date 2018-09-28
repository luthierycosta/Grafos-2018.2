#include "../headers/grafo.h"
#include "../headers/vertice.h"
#include "../headers/lerArquivo.h"
#include "../headers/imprime.h"
#include <iostream>

using namespace std;

int main() {

	Grafo grafo1;

	lerArquivo(grafo1, "arquivos/karate.txt");
	cout << grafo1 << endl;

	imprimeGraus(grafo1);
	cout << "\n";

	imprimeCoefAglomeracao(grafo1);

	return 0;
}