#include "../headers/grafo.h"
#include "../headers/vertice.h"
#include "../headers/lerArquivo.h"
#include <iostream>
#include <cstring>

using namespace std;

int main() {
	Grafo grafo;
	
	lerArquivo(grafo, "entradaProj3TAG.txt");
	cout << grafo << endl;
	
	return 0;
}
