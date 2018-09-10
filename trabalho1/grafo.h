#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

typedef vector< vector<int> > Grafo;

int grau(Grafo&);
void addAresta(Grafo&, int, int);
bool existeAresta(Grafo&, int, int);
void imprimeGrau(Grafo&);
void imprimeGrafo(Grafo&);