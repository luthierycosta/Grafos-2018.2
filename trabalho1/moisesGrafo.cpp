#include <bits/stdc++.h>

using namespace std;

vector<int> checkIntersection (vector<int>& lista1, vector<int>& lista2){
    vector<int> res;
    for(int i=0; i<(int)lista1.size(); i++){
        for(int j=0; j<(int)lista2.size(); j++){
            if(lista1[i] == lista2[j])
                res.push_back(lista1[i]);
        }
    }
    return res;
}

void maximal(vector<vector< int> >& graph, vector< int>& clique, vector< int>& repetidos, vector< int>& P){
	if(P.size() == 0 && repetidos.size() == 0){
		//clique sao maximal
	}
    vector<int> Ptemp, Xtemp; // essa vai ser a lista de intersecoes entre P(P) e as adjacencias do vertice atual(i)
	for(int i = 0; i < (int)P.size(); i++){ // percorre todos os vertices em P (primeira iteracao = tds vertices do grafo)
		clique.push_back(P[i]); // coloco o primeiro vertice de teste em clique
        Ptemp = checkIntersection(P, graph[clique[(int)clique.size()-1]]);
        Xtemp = checkIntersection(repetidos, graph[clique[(int)clique.size()-1]]);
		maximal(graph, clique, Xtemp, Ptemp);

        repetidos.push_back(i); // marcar os que ja foram testados
	}
}

bool conection(vector<vector< int> >graph, int a, int b){
	for(int i = 0; i < (int)graph[a].size(); i++){
		if(graph[a][i] == b){
			return true;
		}
	}	
	return false;
}

void coefGraph (double coefTotal, int i){
	printf("Coeficiente medio do grafo: %f\n", coefTotal/i);
}

void coefCounter (vector<vector< int> >& graph){
	double coefTotal=0;
	for(int i = 1; i <= (int)graph.size()-1; i++){
		int triangle = 0;
		int nVertice = graph[i].size(); 
		double coef;
		printf("Grau do vertice %d: %d      ", i, nVertice);
		vector< int> relacoes(nVertice);
		for(int j = 0; j < nVertice; j++){
			for(int l = j+1; l < nVertice; l++){
				if(conection(graph, graph[i][j], graph[i][l])){
					triangle++;	
				}
			}
		}
		double possibleTriangle = (nVertice)*(nVertice-1)/2;

		if(nVertice <= 1)
			coef = 0;
		else
			coef = (triangle/possibleTriangle);
		
		coefTotal+= coef;

		printf("Coeficiente de Aglomeração: %f\n", coef);
	}
	coefGraph(coefTotal, (int)graph.size()-1);
}

int main(){


	int vert, ares;
	printf("Quantos vertices? E quantas arestas?\n"); 
	scanf("%d %d\n", &vert, &ares);
	
	vector<vector< int> > graph(vert+1);
	
	for(int i=0; i< ares; i++){ 
		int f, s;
		scanf("%d %d", &f, &s);
		graph[f].push_back(s);
		graph[s].push_back(f);
	}
	printf("n de vertice: %d\n", (int)graph.size()-1);	
	coefCounter(graph);
	int f = (int)graph.size();
	vector< int> clique, repetidos, P[f];
    maximal(graph, clique, repetidos, P);
	return 0;
	}