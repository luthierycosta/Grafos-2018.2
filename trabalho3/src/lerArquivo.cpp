#include "../headers/grafo.h"
#include "../headers/vertice.h"
#include "../headers/lerArquivo.h"
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
	int Fid, Fhabilitacoes, Fpref1, Fpref2, Fpref3, Fpref4, Fpref5;
	int Fvaga1, Fvaga2;
	while(fgets(linha, MAXLENGTH, arquivo)){//enquanto não chegar no fim do arquivo
				
		if(strstr(linha, "(P")){//(P5, 3): (E10, E20, E5, E27, E11)
			sscanf(linha, "(P%d, %d): (E%d, E%d, E%d, E%d, E%d)", &Fid, &Fhabilitacoes, &Fpref1, &Fpref2, &Fpref3, &Fpref4, &Fpref5);
			grafo.addVertice(new Professor(Fid, Fhabilitacoes, Fpref1, Fpref2, Fpref3, Fpref4, Fpref5));
		}else if(strstr(linha, "(E")){//(E10):(1):(2)
			if(strlen(linha) < 10){
				sscanf(linha, "(E%d):(%d)", &Fid, &Fvaga1);
				grafo.addVertice(new Escola(Fid, Fvaga1));
			}else{
				sscanf(linha, "(E%d):(%d):(%d)", &Fid, &Fvaga1, &Fvaga2);
				grafo.addVertice(new Escola(Fid, Fvaga1, Fvaga2));
			}
		}
		else continue;
	}
	grafo.setCandidatos();

	fclose(arquivo);
}
