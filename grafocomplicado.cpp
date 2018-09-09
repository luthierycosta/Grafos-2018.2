#include <iostream>		// cin e cout
#include <algorithm>	// max
#include <vector>

using namespace std;

class Grafo {
	vector<Vertice> vertices;

public:
	Grafo(int qtd_vertices) {
		for(int i = 1; i <= qtd_vertices; i++)
			this.addVertice(i);
	}

	~Grafo() {
		for (Vertice v: vertices) delete(v);
	}

	void lerArquivo() { }
	

	void addVertice(int id) {
		vertices.push_back(new Vertice(id));
	}

	void addAresta(int id_a, int id_b) {
		Vertice v1 = find(id_a);
		Vertice v2 = find(id_b);
		v1.push_back(v2);
		v2.push_back(v1);
	}

	bool existeAresta(int id_a, int id_b) {
		Vertice v1 = find(id_a);
		Vertice v2 = find(id_b);

		for (Vertice adj: v1.adj_list)
			if (adj.id() == v2.id())
				return true;

		return false;
	}

	Vertice find(int id) {
		for(Vertice v: vertices)
			if(v.id() == id)
				return v;

		throw invalid_argument; 
	}

	int grau() {
		int res = 0;
		for (Vertice v: vertices)
			res = max(res, v.grau());

		return res;
	}

	void imprimeGrau() {
		for(Vertice v: vertices)
			v.imprimeGrau();
	}

	void imprime() {
		cout << "\nGrafo:\n";
		for(Vertice v: vertices)
			v.imprime();

		cout << endl;
	}

	bool conectado() {
		for (Vertice v: vertices)
			if (!v.conectado())
				return false;

		return true;
	}
}

class Vertice {
public:
	int id;
	vector<Vertice> adj_list;

	Vertice(int new_id) {
		this.id = new_id;
	}

	void push_back(Vertice v) {
		adj_list.push_back(v);
	}

	int grau() {
		return adj_list.size;
	}

	void imprimeGrau() {
		cout << "Vértice "<< id <<" tem grau "<< grau() << endl;
	}

	void imprime() {
		cout << "["<< id <<"]";
		for (Vertice v: adj_list)
			cout <<" -> "<< v.id();
	}

	bool conectado() {
		return (adj_list.size != 0);
	}
}