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
	
	vector<char*> fluxo(35);
	
	ifstream arquivo(nome_arquivo);
	if(!arquivo.is_open()){
		throw ("Erro ao ler arquivo");	
	}else{	
		string linha_atual;
		char* linha_convertida;
		int id=0;
		
		while(getline(arquivo, linha_atual)){
			char* Fdisciplina;
			int Fcreditos, Fdificuldade, Fsource, Freceive;
			
			linha_convertida = (char*) linha_atual.c_str();
			
			if(strstr(linha_convertida, "id ")){
				id++;
				sscanf(linha_convertida, "id %*d %[^,], %*s %d, %*s %d", Fdisciplina, &Fcreditos, &Fdificuldade);
				printf("id: %d|disciplina: %s| creditos: %d| dificuldade: %d\n", id, Fdisciplina, Fcreditos, Fdificuldade);
				//grafo.addVertice(Fdisciplina, Fcreditos, Fdificuldade);
			}
			else if(strstr(linha_convertida, "source: ")){
				sscanf(linha_convertida, "%*s %*s (%d)", &Fsource);
			}
			else if(strstr(linha_convertida, "receive:")){
				sscanf(linha_convertida, "%*s %*s (%d)", &Freceive);
				printf("%d é pre requisito de %d\n", Fsource, Freceive);
			}
			else continue;
		}
	}
	arquivo.close();
}
