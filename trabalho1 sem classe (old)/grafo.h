/*
Montagem do grafo, implementado por vetores de vetores de inteiros,
onde cada vetor no índice i contém como valores os índices
dos vértices adjacentes ao vértice i.

@author Lucas Vinicius M. Pinheiro
@author Luthiery C. Cavalcante
*/

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

typedef vector< vector<int> > Grafo;

/*
@param Endereço para uma estrutura do tipo Grafo
@return int correspondente ao grau do vértice.
*/
int grau(Grafo&);

/*
Função para adicionar arestas no grafo.
@param Endereço para uma estrutura do tipo Grafo, int vertice1 e vertice2
@return void
*/
void addAresta(Grafo&, int, int);

/*
Função para conferir a existencia de arestas.
@param Endereço para uma estrutura do tipo Grafo, int vertice1 e vertice2
@return bool true caso haja uma aresta conectando vertice1 e vertice 2
*/
bool existeAresta(Grafo&, int, int);

/*
Função para imprimir o grau de um vértice
@param Endereço para uma estrutura do tipo Grafo
@return void
*/
void imprimeGrau(Grafo&);

/*
Função para imprimir o grafo, como uma lista de adjacências
@param Endereço para uma estrutura do tipo Grafo
@return void
*/
void imprimeGrafo(Grafo&);
