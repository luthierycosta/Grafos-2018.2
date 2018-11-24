#include "../headers/lerArquivo.h"
#include "../headers/grafo.h"
#include "../headers/vertice.h"
#include <fstream>
#include <string>
#include <cstdio>

using namespace std;

void lerArquivo(Grafo& grafo, string nome_arquivo) {
	
	ifstream arquivo(nome_arquivo);	
	if(!arquivo.is_open()) {				//checa se o arquivo foi lido
		printf("Erro ao ler arquivo\n");
		exit(-1);	
	}
	int source, target;
	while(arquivo >> source >> target) {	//enquanto não chegar no fim do arquivo	

		if(!grafo.existeVertice(source))
			grafo.addVertice(new Vertice(source));
		if(!grafo.existeVertice(target))
			grafo.addVertice(new Vertice(target));

		grafo.addAresta(source, target);
	}
	arquivo.close();
}
