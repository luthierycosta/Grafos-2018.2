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

	void lerArquivo() {
		
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
					this.addVertice(id);
				}
				else if (strstr(linha_convertida, "source")) {
					sscanf(linha_convertida, " %*s %d", &source);
				}
				else if (strstr(linha_convertida, "target")) {
					sscanf(linha_convertida, " %*s %d", &target);
					this.addAresta(source, target);
				}
				else continue;
			}
		}
		karate.close();
	}
	

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

		if (v1.existeAresta(v2))
			return true;
		else
			return false;
	}

	Vertice find(int id) {
		for(Vertice v: vertices)
			if(v.id == id)
				return v;

		throw invalid_argument; 
	}

	int grau() {
		int res = 0;
		for (Vertice v: vertices)
			res = max(res, v.grau());

		return res;
	}

	void imprimeGraus() {
		for(Vertice v: vertices)
			cout << "Vértice "<< v.id <<" tem grau "<< v.grau() << endl;

		cout << "Grau do grafo: "<< this.grau() << endl;
	}

	void imprimeGrafo() {
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

	double coefAglomeracao() {

		if((int)vertices.size() == 0)
			return 0.0;
		else {
			double soma_coefs = 0;
			for(Vertice v: vertices)
				soma_coefs += v.coefAglomeracao();

			return soma_coefs/(int)vertices.size();
		}
	}
}

class Vertice {
public:
	int id;
	vector<Vertice> adjascentes;

	Vertice(int new_id) {
		this.id = new_id;
	}

	void push_back(Vertice v) {
		adjascentes.push_back(v);
	}

	int grau() {
		return adjascentes.size();
	}

	bool existeAresta(Vertice v) {
		for (Vertice adj: adjascentes)
			if (adj.id == v.id)
				return true;

		return false;
	}

	void imprimeVertice() {
		cout << "["<< id <<"]";
		for (Vertice v: adjascentes)
			cout <<" -> "<< v.id;
	}

	bool conectado() {
		return (adjascentes.size() != 0);
	}

	double coefAglomeracao() {

		int n_adj = this.grau();
		
		if (n_adj <= 1) {				// se o vértice tem 1 ou 0 adjascentes, não há triângulos possíveis
			return 0.0;
		} else {
		
			int triangulos = 0;
			for(int i = 0; i < n_adj; i++) {
				for(int j = i+1; j < n_adj; j++) {				// i e j percorrem a lista de adj. do vértice
					
					if (adjascentes[i].existeAresta(adjascentes[j]))
						triangulos++;
				}
			}
			return (2*triangulos/(n_adj*(n_adj-1)));
		}
	}
}