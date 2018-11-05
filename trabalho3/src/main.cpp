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
	
	vector<pair<int, int> > pares = grafo.matching();

	for(int i=0; i<(int)pares.size(); i++){
		cout << "escola " << i+1 << " contratou professor " << pares[i+1].first << " pra vaga 1";
		if(pares[i+1].second != 0){
			cout << " e professor " << pares[i+1].second << " pra vaga 2";
		}
		cout << endl;
	}

	return 0;
}
