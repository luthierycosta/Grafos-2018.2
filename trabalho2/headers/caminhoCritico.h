#ifndef CAMINHO_CRITICO_H
#define CAMINHO_CRITICO_H

#include "grafo.h"
#include "vertice.h"
#include <deque>
#include <vector>

using namespace std;

/**
 * @brief	Função para encontrar o caminho crítico do fluxo
 *	
 * Primeiro passo é encontrar o peso máximo para se concluir cada matéria e guardar os valores num vector, e achar qual o materia de maior
 * peso a ser concluída, sendo essa a ultima materia do caminho crítico.
 * Após isso, visitaremos recursivamente os pré requisitos dessa matéria, por meio do grafo inverso,
 * para checar qual dos pré requisitos fazem parte do caminho crítico,
 * comparando a distancia da matéria pré requisito com a matéria atual e conferindo se a soma distancia[pré requisto] + peso(matéria atual) é
 * igual à distancia(matéria atual). caso seja igual colocamos "matéria pré requisito" numa lista como parte do caminho crítico.
 * Ao final, imprimimos a lista (em ordem inversa, pois começamos a partir da ultima matéria)
 * 
 * @param grafo1	O grafo do fluxo.
 */
void caminhoCritico(Grafo& grafo1);



vector<int> caminhoCriticoAux(int n, vector<int> distancia, Grafo& grafo, deque<Vertice> ordenacao, vector<int>& camCriticoAux);

#endif