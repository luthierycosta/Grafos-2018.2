#include <vector>

using namespace std;

class Vertice {
public:
	int id;
	vector<int> adjascentes;

	Vertice(int new_id);

	void push_back(int v);

	bool existeAresta(int v);

	bool conectado();

	int grau();

	void imprime();

};