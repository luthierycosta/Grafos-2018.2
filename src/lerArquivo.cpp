#include "../headers/grafo.h"
#include "../headers/vertice.h"
#include "../headers/lerArquivo.h"
#include <fstream>
#include <string>
#include <cstring>
#include <cstdio>

using namespace std;

void lerArquivo(Grafo& grafo, string nome_arquivo) {
		
	ifstream arquivo(nome_arquivo);

	if (!arquivo.is_open()) {
		throw ("Erro ao ler arquivo");
	} else {

		string linha_atual;
		char* linha_convertida;
		int id, source, target;

		while (getline(arquivo, linha_atual)) {				// linha_atual receberá cada linha do arquivo por vez
			
			linha_convertida = (char*) linha_atual.c_str();	// converte pra string de c (char*)
			
			if (strstr(linha_convertida, "id")) {
				sscanf(linha_convertida, " %*s %d", &id);
				grafo.addVertice(id);
			}
			else if (strstr(linha_convertida, "source")) {
				sscanf(linha_convertida, " %*s %d", &source);
			}
			else if (strstr(linha_convertida, "target")) {
				sscanf(linha_convertida, " %*s %d", &target);
				grafo.addAresta(source, target);
			}
			else continue;
		}
	}
	arquivo.close();
}