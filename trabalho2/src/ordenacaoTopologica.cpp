#include "../headers/grafo.h"
#include "../headers/vertice.h"
#include <deque>
#include <map>
#include <string>
#include <algorithm> // for using reverse in a vector

using namespace std;

vector<int> camCriticoAux;

void ordenacaoTopologicaAux(Vertice& v, map<string,bool>& visitados, deque<Vertice>& fila_ordenacao) {

	visitados[v.id.getNome()] = true;

	for(Vertice* w: v.adjacentes)
		if (!visitados[w->id.getNome()])
			ordenacaoTopologicaAux(*w, visitados, fila_ordenacao);

	fila_ordenacao.push_front(v);
}

deque<Vertice> ordenacaoTopologica(Grafo& grafo) {
	
	map<string, bool> visitados;
	deque<Vertice> fila_ordenacao;

	for(Vertice& v: grafo.vertices)
		visitados[v.id.getNome()] = false;

	for(Vertice& v: grafo.vertices)
		if (!visitados[v.id.getNome()])
			ordenacaoTopologicaAux(v, visitados, fila_ordenacao);

	return fila_ordenacao;
}

vector<int> caminhoCriticoAux(int n, vector<int> distancia, Grafo& grafoPre, deque<Vertice> ordenacao){
	camCriticoAux.push_back(n);
	vector<Vertice*> requisitos = ordenacao[n-1].adjacentes;
	if(requisitos.size() < 1){
		return camCriticoAux;	
	}
	reverse(requisitos.begin(), requisitos.end());
	for(Vertice* v: requisitos){
		if(distancia[n] == distancia[v->id.getPosicao()] + ordenacao[n-1].id.peso()){
			caminhoCriticoAux(v->id.getPosicao(), distancia, grafoPre, ordenacao);
		}
	}
	return camCriticoAux;
}

void caminhoCritico(Grafo& grafoFluxo, Grafo& grafoPre){
	deque<Vertice> ordenacao = ordenacaoTopologica(grafoFluxo);
	deque<Vertice> ordenacaoInversa = ordenacaoTopologica(grafoPre);
	vector<int> distancia((int)ordenacao.size(), 0); //vector de distancias com nVertices posições todas iniciadas com 0
	reverse(ordenacaoInversa.begin(), ordenacaoInversa.end());	
	for(Vertice& v: ordenacaoInversa){ // achar a distancia maxima de cada vertice
		if(v.grau() <= 0){
			distancia[v.id.getPosicao()] = v.id.peso();	
		}
		else{
			vector<Vertice*> requisitos = v.adjacentes;
			for(int i = 0; i < requisitos.size(); i++){
				distancia[v.id.getPosicao()] = max(distancia[v.id.getPosicao()], distancia[requisitos[i]->id.getPosicao()] + v.id.peso());
			}
		}
	}
	int maximo=0, aux;
	for(int i=1; i< (int)ordenacaoInversa.size(); i++){	
		aux = max(distancia[i], distancia[i-1]);
		maximo = max(aux, maximo);
	}
	for(int i=0; i< (int)ordenacaoInversa.size(); i++){	
		if(distancia[i]==maximo)	
			aux = i;
	}

	vector<int> camCritico = caminhoCriticoAux(aux, distancia, grafoPre, ordenacaoInversa);
	
	reverse(camCritico.begin(), camCritico.end());
	printf("\nCaminho Crítico:\n");
	for(int i=0; i<camCritico.size(); i++){
		cout << i+1 << "º: " << ordenacaoInversa[camCritico[i]-1].id.getNome() << endl;
	}
	cout << "Com peso total de " << distancia[aux] << endl;
}

