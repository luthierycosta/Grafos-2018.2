#include "../headers/grafo.h"
#include "../headers/vertice.h"
#include "../headers/lerArquivo.h"
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main() {
	Grafo grafo;
	
	lerArquivo(grafo, "entradaProj3TAG.txt");
	cout << grafo << endl;
	
	grafo.emparelhamento(70);

	for(Escola* esc: grafo.escolas) {
		cout << "E"<< esc->id;
		
		if(esc->contratado1)
			cout << " - vaga 1: P"<< esc->contratado1->id;
		if(esc->contratado2)
			cout << " - vaga 2: P"<< esc->contratado2->id;

		cout << endl;
	}

	return 0;
}
