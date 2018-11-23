#include "../headers/lerArquivo.h"
#include "../headers/grafo.h"
#include "../headers/vertice.h"
#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>

#define MAXLENGTH 150

using namespace std;

void lerArquivo(Grafo& grafo, string nome_arquivo) {
	
	FILE* arquivo = fopen((char*)nome_arquivo.c_str(), "r");

	if(!arquivo) {// checa se o arquivo foi lido
		printf("Erro ao ler arquivo\n");
		exit(-1);	
	}
	int source, target;
	while(fscanf(arquivo, "%d %d", &source, &target)){//enquanto não chegar no fim do arquivo		
		
		if(!grafo.existeVertice(source))
			grafo.addVertice(new Vertice(source));
		if(!grafo.existeVertice(target))
			grafo.addVertice(new Vertice(target));

		grafo.addAresta(source, target);
	}

	fclose(arquivo);
}
