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
	//declara as variáveis que serão usadas para armazenar dados do arquivo
	char linha[MAXLENGTH];
	//int Fid, Fhabilitacoes, Fpref1, Fpref2, Fpref3, Fpref4, Fpref5;
	//int Fvaga1, Fvaga2;
	while(fgets(linha, MAXLENGTH, arquivo)){//enquanto não chegar no fim do arquivo
				


	}

	fclose(arquivo);
}
