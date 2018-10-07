#include "../headers/disciplina.h"
#include "../headers/grafo.h"
#include "../headers/vertice.h"
#include "../headers/lerArquivo.h"
#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>

#define MAXLENGTH 150

using namespace std;

void lerArquivo(Grafo& grafo, string nome_arquivo){
	
	FILE* arquivo = fopen((char*)nome_arquivo.c_str(), "r");

	if(!arquivo) {
		printf("Erro ao ler arquivo\n");
		exit(-1);	
	} else{
		
		char linha[MAXLENGTH], Fdisciplina[MAXLENGTH], Fsource[MAXLENGTH], Freceive[MAXLENGTH];
		int Fcreditos, Fdificuldade;
		//int id=0;
		
		while(fgets(linha, MAXLENGTH, arquivo)){
					
			if(strstr(linha, "id ")){
				//id++;
				sscanf(linha, "id %*d %[^,], %*s %d, %*s %d", Fdisciplina, &Fcreditos, &Fdificuldade);
				//printf("id: %d|disciplina: %s| creditos: %d| dificuldade: %d\n", id, Fdisciplina, Fcreditos, Fdificuldade);
				grafo.addVertice(Fdisciplina, Fcreditos, Fdificuldade);
			}
			else if(strstr(linha, "source: ")){
				sscanf(linha, "%*s %s (%*d)", Fsource);
			}
			else if(strstr(linha, "receive:")){
				sscanf(linha, "%*s %s (%*d)", Freceive);
				//printf("%s é pre requisito de %s\n", Fsource, Freceive);
				grafo.addAresta(Fsource, Freceive);
			}
			else continue;
		}
	}
	fclose(arquivo);
}
