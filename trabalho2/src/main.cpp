#include "../headers/grafo.h"
#include "../headers/vertice.h"
#include "../headers/disciplina.h"
#include "../headers/lerArquivo.h"
#include "../headers/ordenacaoTopologica.h"
#include "../headers/caminhoCritico.h"
#include <iostream>
#include <deque>

using namespace std;

int main() {

	Grafo grafoFluxo;

	lerArquivo(grafoFluxo, "arquivos/FluxoSend.txt");
	cout << grafoFluxo << endl;

	deque<Vertice> ordenacao = ordenacaoTopologica(grafoFluxo);

	cout << "ORDENAÇÃO TOPOLÓGICA: " << endl;
	for(int i = 0; i < (int)ordenacao.size(); i++)
		cout << i+1 <<". "<< ordenacao[i].getNome() << endl;;
	
	caminhoCritico(grafoFluxo);

	return 0;
}
