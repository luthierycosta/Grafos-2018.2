#include <bits/stdc++.h>

using namespace std;

void nGrau (vector<vector< int> > graph, int vert){
	for (int i = 0; i < vert; i++)
		{
			printf("vertice %d grau: %d\n", i, graph[i].size());
		}	
}

int main(){
	int vert = 9;
	int ares = 10;
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

