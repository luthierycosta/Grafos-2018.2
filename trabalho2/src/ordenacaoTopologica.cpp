#include "../headers/grafo.h"
#include "../headers/vertice.h"
#include <deque>
#include <map>
#include <string>

using namespace std;

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
	vector<int> camCritico;
	camCritico.push_back(n);
	vector<Vertice*> requisitos = ordenacao[n].adjacentes;//-- tentando adquirir numa lista de vertices os pré requisitos pro vertice n
	for(Vertice* v: requisitos){
		if(distancia[n] == distancia[v->id.getPosicao()] + v->id.peso()){
			caminhoCriticoAux(v->id.getPosicao(), distancia, grafoPre, ordenacao);
		}else
			continue;
	}
	return camCritico;
}

void caminhoCritico(Grafo& grafoFluxo, Grafo& grafoPre){
	deque<Vertice> ordenacao = ordenacaoTopologica(grafoFluxo);
	deque<Vertice> ordenacaoInversa = ordenacaoTopologica(grafoPre);
	vector<int> distancia((int)ordenacao.size(), 0); //vector de distancias com nVertices posições todas iniciadas com 0
	for(Vertice& v: ordenacao){ // achar a distancia maxima de cada vertice
		printf("Distancia do vertice %d antes = %d| peso do vertice = %d\n", v.id.getPosicao(), distancia[v.id.getPosicao()], v.id.peso());
		if(v.grau() <= 0){//****IMPORTANTE!******, o grau que está conferindo é o grau de saída e não o de entrada, como deveria ser. isso tá zoando o resto do código (to pensando positivamente aq, as vezes tem mais problemas)
			distancia[v.id.getPosicao()] = ordenacao[v.id.getPosicao()].id.peso();
			printf("Esse é o primeiro\n");		
		}
		else{
			vector<Vertice*> requisitos = v.adjacentes;
			printf("ah, o tamanho de requisitos é %d\n", (int)requisitos.size());
			for(int i = 0; i < requisitos.size(); i++){
				distancia[v.id.getPosicao()] = max(distancia[v.id.getPosicao()], distancia[i] + ordenacaoInversa[v.id.getPosicao()].id.peso());
				printf("visitando o %dº vertice pre requisito, que é = ", i);
				cout << *requisitos[i] << endl;
				printf("e a distancia maxima agora é %d\n", distancia[v.id.getPosicao()]);
			}
			printf("Esse nao\n");	
		}
		printf("Distancia do vertice %d = %d\n\n", v.id.getPosicao(), distancia[v.id.getPosicao()]);
	}
	int maximo;
	for(int i=1; i< (int)ordenacao.size(); i++){ // achar a maior distancia entre todas as distancias (aka vertice final do caminho critico)
		maximo = max(distancia[i], distancia[i-1]);
	}
	vector<int> camCritico = caminhoCriticoAux(maximo, distancia, grafoPre, ordenacao);
	
	for(int i= (int)camCritico.size(); i>0; i--){ //printa os vertices do caminho critico (em ordem inversa pq comecei a procurar a partir do ultimo)
		printf("Caminho Crítico:\n");
		cout << ordenacao[i].id.getNome() << endl;
		printf("Com %d de peso total.\n", maximo);
	}
}

