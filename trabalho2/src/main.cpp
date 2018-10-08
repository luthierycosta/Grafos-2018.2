#include "../headers/grafo.h"
#include "../headers/vertice.h"
#include "../headers/disciplina.h"
#include "../headers/lerArquivo.h"
#include "../headers/ordenacaoTopologica.h"
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
		cout << i+1 <<". "<< ordenacao[i].id.getNome() << endl;;
	
	Grafo grafoPre = grafoFluxo.inverso();
	cout << "grafo de prerequisitos:" << grafoPre << endl;

	deque<Vertice> ordenacaoInversa = ordenacaoTopologica(grafoPre);
	/*
	cout << "ORDENAÇÃO TOPOLÓGICA INVERSA: " << endl;
	for(int i = 0; i < (int)ordenacaoInversa.size(); i++)
		cout << i+1 <<". "<< ordenacaoInversa[i].id.getNome() << endl;;
	*/

	caminhoCritico(grafoFluxo);

	return 0;
}
