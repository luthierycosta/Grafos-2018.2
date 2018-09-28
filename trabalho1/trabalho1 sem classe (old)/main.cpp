#include "lerArquivo.h"
#include "grafo.h"
#include "coefAglomeracao.h"


using namespace std;

/*
Projeto I de Teoria e Aplicação de Grafos
Alunos: Luthiery Costa Cavalcante (17/0040631) e Lucas Vinicius Magalhães Pinheiro (17/0061001)
Professor Díbio

Arquivo principal 
*/

int main() {
	
	Grafo g1 = lerArquivo();
	imprimeGrafo(g1);
	cout << "\n";

	imprimeGrau(g1);
	cout << "\n";
	
	coefAglomeracao(g1);

	return 0;
}
