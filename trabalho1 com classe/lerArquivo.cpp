#include "grafo.h"
#include <fstream>
#include <string>
#include <cstring>
#include <cstdio>

using namespace std;

void Grafo::lerArquivo() {
		
	ifstream karate("arquivos/karate.txt");

	if (!karate.is_open()) {
		throw "Erro ao ler arquivo";
	} else {

		string linha_atual;
		char* linha_convertida = NULL;
		int id, source, target;

		while (getline(karate, linha_atual)) {				// linha_atual receberá cada linha do arquivo por vez
			
			linha_convertida = (char*) linha_atual.c_str();	// converte pra string de c (char*)
			
			if (strstr(linha_convertida, "id")) {
				sscanf(linha_convertida, " %*s %d", &id);
				addVertice(id);
			}
			else if (strstr(linha_convertida, "source")) {
				sscanf(linha_convertida, " %*s %d", &source);
			}
			else if (strstr(linha_convertida, "target")) {
				sscanf(linha_convertida, " %*s %d", &target);
				addAresta(source, target);
			}
			else continue;
		}
	}
	karate.close();
}