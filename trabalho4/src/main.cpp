#include "../headers/grafo.h"
#include "../headers/vertice.h"
#include "../headers/lerArquivo.h"
#include <iostream>

using namespace std;

int main() {
	Grafo grafo;
	
	lerArquivo(grafo, "email-Eu-core.txt");
	cout << grafo << endl;
	
	return 0;
}
