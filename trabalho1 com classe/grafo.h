#include "vertice.h"
#include <vector>

using namespace std;

class Grafo {
	vector<Vertice> vertices;

public:
	Grafo();
	Grafo(int qtd_vertices);

	void lerArquivo();
	
	void addVertice(int id);

	void addAresta(int id_a, int id_b);

	bool existeAresta(int id_a, int id_b);

	Vertice& getVertice(int id);

	bool conectado();

	int grau();

	void imprimeGraus();

	void imprime();

	void coefAglomeracao();
};

