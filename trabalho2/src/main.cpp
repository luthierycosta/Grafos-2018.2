#include "../headers/grafo.h"
#include "../headers/vertice.h"
#include "../headers/disciplina.h"
#include "../headers/lerArquivo.h"
#include "../headers/ordenacaoTopologica.h"
#include <iostream>
#include <deque>

using namespace std;

int main() {

	Grafo grafoFluxo, grafoPre;

	/*grafo2.addVertice("ABC", 1, 2);
	grafo2.addVertice("DEF", 3, 4);
	grafo2.addVertice("GHI", 5, 6);
	grafo2.addAresta("ABC", "DEF");
	grafo2.addAresta("GHI", "ABC");
	*/
	lerArquivo(grafoFluxo, grafoPre, "FluxoSend.txt");
	cout << grafoFluxo << endl;
	cout << "grafo de prerequisitos:" << grafoPre << endl;

	deque<Vertice> ordenacao = ordenacaoTopologica(grafoFluxo);

	cout << "ORDENAÇÃO TOPOLÓGICA: " << endl;
	for(int i = 0; i < (int)ordenacao.size(); i++)
		cout << i+1 <<". "<< ordenacao[i].id.getNome() << endl;;
	

	deque<Vertice> ordenacaoInversa = ordenacaoTopologica(grafoPre);

	cout << "ORDENAÇÃO TOPOLÓGICA INVERSA: " << endl;
	for(int i = 0; i < (int)ordenacaoInversa.size(); i++)
		cout << i+1 <<". "<< ordenacaoInversa[i].id.getNome() << endl;;
	

	caminhoCritico(grafoFluxo, grafoPre);

	return 0;
}
