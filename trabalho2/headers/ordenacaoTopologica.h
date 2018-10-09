#ifndef ORDENACAO_H
#define ORDENACAO_H

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

#endif