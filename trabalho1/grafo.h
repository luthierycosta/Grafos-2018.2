#include <vector>
#include <algorithm>		// max	

using namespace std;

typedef vector< vector<int> > Grafo;

int grau(Grafo&);
void addAresta(Grafo&, int, int);
bool existeAresta(Grafo&, int, int);