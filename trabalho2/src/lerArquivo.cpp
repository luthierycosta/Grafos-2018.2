#include "../headers/disciplina.h"
#include "../headers/grafo.h"
#include "../headers/vertice.h"
#include "../headers/lerArquivo.h"
#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>

using namespace std;

void lerArquivo(Grafo& grafo, string nome_arquivo){
	
	ifstream arquivo(nome_arquivo);
	if(!arquivo.is_open()){
		throw ("Erro ao ler arquivo");	
	}else{	
		string linha_atual;
		char* linha_convertida;
		char* Fdisciplina;
		char* Fsource;
		char* Freceive;
		int Fcreditos, Fdificuldade;	

		while(getline(arquivo, linha_atual)){
			linha_convertida = (char*) linha_atual.c_str();
			
			if(strstr(linha_convertida, "id")){
				sscanf(linha_convertida, "id %[^,], %*s %d, %*s %d", Fdisciplina, &Fcreditos, &Fdificuldade);
				//grafo.addVertice(Fdisciplina, Fcreditos, Fdificuldade);
				printf("disciplina: %s| creditos: %d| dificuldade: %d\n", Fdisciplina, Fcreditos, Fdificuldade);
			}
			else if(strstr(linha_convertida, "source: ")){
				//sscanf(linha_convertida, "source: %[^\n]", Fsource);
				continue;
			}
			else if(strstr(linha_convertida, "receive: ")){
				//sscanf(linha_convertida, "receive: %[^\n]", Freceive);
				//grafo.addAresta (Fsource, Freceive);
				continue;
			}
			else if(strstr(linha_convertida, "edge")){
				break;			
			}
			else continue;
		}
	}
	arquivo.close();
}
