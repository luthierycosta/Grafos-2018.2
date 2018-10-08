#include "grafo.h"
#include "vertice.h"
#include <deque>
#include <map>

using namespace std;

/**
 * @brief      Produz, em um deque, uma ordenação topológica do grafo acíclico digirido (DAG) informado.
 * 
 * Numa ordenação topológica, um vértice A vem antes de B se existe um caminho de A para B.
 * 
 * O algoritmo percorre o grafo de forma similar à do algoritmo de busca DFS (Depth-First Search),
 * com a diferença de que o vértice só é processado depois de serem processados todos os seus adjacentes.
 *
 * @param      grafo  O DAG informado
 *
 * @return     Uma ordenação topológica do grafo.
 */
deque<Vertice> ordenacaoTopologica(Grafo& grafo);

/**
 * @brief      Função auxiliar da função de ordenação topológica, responsável por processar cada vértice.
 * 
 * Primeiro, ela marca o vértice v como visitado.
 * Depois, chama-se recursivamente a todos os adjacentes de v.
 * Por fim, insere v no deque.
 *
 * @param      v               O vértice
 * @param      visitados       O vetor que faz o registro dos vértices já visitados.
 * @param      fila_ordenacao  O deque a ser retornado pela função principal.
 */
void ordenacaoTopologicaAux(Vertice& v, map<string,bool>& visitados, deque<Vertice>& fila_ordenacao);

/**
 * @brief	Função para encontrar o caminho crítico do fluxo
 *	
 * Primeiro passo é encontrar o peso máximo para se concluir cada matéria e guardar os valores num vector, e achar qual o materia de maior
 * peso a ser concluída, sendo essa a ultima materia do caminho crítico.
 * Após isso, visitaremos recursivamente os pré requisitos dessa matéria para checar qual dos pré requisitos fazem parte do caminho crítico,
 * comparando a distancia da matéria pré requisito com a matéria atual e conferindo se a soma distancia[pré requisto] + peso(matéria atual) é
 * igual à distancia(matéria atual). caso seja igual colocamos "matéria pré requisito" numa lista como parte do caminho crítico.
 * Ao final, imprimimos a lista (em ordem inversa, pois começamos a partir da ultima matéria)
 * 
 * @param grafo1	O grafo do fluxo
 * @param grafo2	Um grafo cuja lista de adjacencias são os pré requisitos, e não as matérias seguintes.
 */
void caminhoCritico(Grafo& grafo1, Grafo& grafo2);



vector<int> caminhoCriticoAux(int n, vector<int> distancia, Grafo& grafo, deque<Vertice> ordenacao);
