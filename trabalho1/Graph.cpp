#include <bits/stdc++.h>

using namespace std;

bool conection(vector<vector< int> >graph, int a, int b){
	//printf("-------------\n");//
	for(int i = 0; i < (int)graph[a].size(); i++){
		//printf("aqui confiro se é triangulo mesmo. os vertices '%d' e '%d'\n", (int)graph[a][i], b);//
		if(graph[a][i] == b){
		//printf("-------------\n");//
			return true;
		}
	}	
	return false;
	//printf("-------------\n");
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
		//printf("os contatos:\n");//
		for(int j = 0; j < nVertice; j++){
			//printf(" %d", graph[i][j]);//
			for(int l = j+1; l < nVertice; l++){
				//printf("\nagora comparando '%d' e '%d',", (int)graph[i][j], (int)graph[i][l]);//
				if(conection(graph, graph[i][j], graph[i][l])){
					triangle++;	
					//printf(" e realmente é um triangulo\n");//
				}else{
					//printf(" e nao eh triangulo\n");//
				}
		
			}
		}
		double possibleTriangle = (nVertice)*(nVertice-1)/2;

		//printf("\nn de triangulo: %d\nn de triangulos possiveis: %f\n",
 //triangle, possibleTriangle);//
		if(nVertice <= 1)
			coef = 0;
		else
			coef = (triangle/possibleTriangle);
		
		coefTotal+= coef;

		printf("Coeficiente de Aglomeração: %f\n", coef);
	}
	//printf("Somatorio: %f, tamanho: %d\n", coefTotal, (int)graph.size());
	coefGraph(coefTotal, (int)graph.size()-1);
}



/*
vector< vector<int> > getFile(){

	ifstream karate("karate.txt");

	if(karate.is_open()){

		string line, get;
		int temporary;
		vector< vector<int> > graph();
		graph().push_back[0];

		while(getLine(karate, line)){
			int vert1, vert2;
			if(strstr(line, "id")){
				graph.push_back(vector<int>());
			}else if(strstr(line, "edge")){
				sscanf(line.c_str(), "%d %d", &vert1, &vert2);
				graph[vert1].push_back(vert2);
				graph[vert2].push_back(vert1);
			}else continue;
		}
	}	
	karate.close();
	}else{
		printf("é n deu viado");
	}


	return graph;
}
*/

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
		
	//vector< vector<int> > graph = getFile();
	printf("n de vertice: %d\n", (int)graph.size()-1);	
	coefCounter(graph);
	return 0;
	}
