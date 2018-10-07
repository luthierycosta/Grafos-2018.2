#include "../headers/grafo.h"
#include "../headers/vertice.h"
#include "../headers/disciplina.h"
#include "../headers/lerArquivo.h"
#include "../headers/ordenacaoTopologica.h"
#include <iostream>
#include <deque>

using namespace std;

int main() {

	Grafo grafo2;

	/*grafo2.addVertice("ABC", 1, 2);
	grafo2.addVertice("DEF", 3, 4);
	grafo2.addVertice("GHI", 5, 6);
	grafo2.addAresta("ABC", "DEF");
	grafo2.addAresta("GHI", "ABC");
*/
	lerArquivo(grafo2, "arquivos/FluxoSend.txt");
	cout << grafo2 << endl;

	deque<Vertice> ordenacao = ordenacaoTopologica(grafo2);

	cout << "ORDENAÇÃO TOPOLÓGICA: " << endl;
	for(int i = 0; i < (int)ordenacao.size(); i++)
		cout << i+1 <<". "<< ordenacao[i].id.getNome() << endl;;

	return 0;
}