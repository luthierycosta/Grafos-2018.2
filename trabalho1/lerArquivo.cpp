#include "lerArquivo.h"

Grafo lerArquivo() {
	
	Grafo grafo1;
	ifstream karate("arquivos/karate.txt");

	if (!karate.is_open()) {
		cout << "Erro ao ler o arquivo." << endl;
	} else {

		grafo1.push_back(vector<int>());					// indice 0, que não tem vetor

		string linha_atual;
		char* linha_convertida = NULL;
		int vert1, vert2;

		while (getline(karate, linha_atual)) {				// linha_atual receberá cada linha do arquivo por vez
			
			linha_convertida = (char*) linha_atual.c_str();	// converte pra string de c (char*)
			
			if (strstr(linha_convertida, "id")) {
				grafo1.push_back(vector<int>());
			}
			else if (strstr(linha_convertida, "source")) {
				sscanf(linha_convertida, " %*s %d", &vert1);
			}
			else if (strstr(linha_convertida, "target")) {
				sscanf(linha_convertida, " %*s %d", &vert2);
				addAresta(grafo1, vert1, vert2);
			}
			else continue;
		}
	}

	karate.close();
	return grafo1;
}
