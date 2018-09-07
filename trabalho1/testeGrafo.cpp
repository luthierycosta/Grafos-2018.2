#include <bits/stdc++.h>
#include <iostream>
#include <fstream>

using namespace std;

void nGrau (vector<vector< int> > graph, int vert){
	for (int i = 0; i < vert; i++)
		{
			printf("vertice %d grau: %ld\n", i, graph[i].size());
		}	
}

void open (const char karate.txt, ios::in)


vector<vector< int> > getFile(){
	ifstream karate;
	karate.open ("karate.txt");

	while(infile)
	//
	// montar o grafo
	//

	karate.close;
}

int main(){
	vector<vector< int> > graph = getFile();
	vector<vector< int> > graph(vert);

	for (int i = 0; i < ares; i++)
	{
		int f, s;
		scanf("%d %d", &f, &s);
		graph[f].push_back(s);
		graph[s].push_back(f);
	}

	nGrau(graph, vert);

	return 0;
}

