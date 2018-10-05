#include "grafo.h"
#include "vertice.h"
#include <stack>

using namespace std;

stack<Vertice> ordenacaoTopologica(Grafo& grafo);
void ordenacaoTopologicaAux(Vertice& v, map<string,bool>& visitados, stack<Vertice>& pilha_ordenacao);