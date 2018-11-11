/**
 * Arquivo-cabeçalho contendo as declarações da classe Grafo
 * e seus atributos e métodos.
 * 
 * @author Lucas Vinicius M. Pinheiro
 * @author Luthiery C. Cavalcante
 */
#ifndef _GRAFO_H_
#define _GRAFO_H_

#include "vertice.h"
#include <vector>
#include <iostream>
#include <functional>

using namespace std;

/**
 * @brief      Grafo não-direcionado sem pesos, cujos vértices representam sei la oq n veio o trab4 ainda.
 * 
 * Usa um vetor público para armazenar seus vértices.
 * 
 * Não há representação do conjunto de arestas. As ligações entre vértices se dão
 * apenas pela manipulação de suas lista de adjacências.
 */
class Grafo {
public:
	vector<Vertice*> vertices;		/** Lista de vértices do grafo.*/
	
	Grafo(); 						/** Cria um grafo vazio. */
	~Grafo();						/** Deleta cada objeto Vertice alocado dinamicamente. */
	
	void addVertice(Vertice* v); 	/** Adiciona um vértice no vetor. */

	bool existeVertice(int id); 	/** Verifica se o dado vértice (id) está presente no grafo.*/

	Vertice* findVertice(int id);	/** Retorna uma referência para o vértice (id), se ele exisitr.*/

	bool existeAresta(Vertice* v1, Vertice* v2);/** Checa se existe uma aresta entre os Vertice v1 e v2. */
	bool existeAresta(int v1, int v2);			/** existeAresta() mas informando os ids dos vértices em vez de ponteiros para Vertice.*/

	void addAresta(Vertice* v1, Vertice* v2);	/** Adiciona uma aresta não direcionada entre v1 e v2, se ela ainda não existe. */
	void addAresta(int v1, int v2);				/** addAresta() mas informando os ids dos vértices em vez de ponteiros para Vertice.*/
	
	void removeAresta(Vertice* v1, Vertice* v2);/**  Remove a aresta (v1, v2), caso ela exista. */
	void removeAresta(int v1, int v2);		/** removeAresta() mas informando os ids dos vértices em vez de ponteiros para Vertice.*/

	void bfs(Vertice* inicial, function<void (Vertice*)> foo);
	void bfs(function<void (Vertice*)> foo);
	
	void dfs(Vertice* inicial, function<void (Vertice*)> foo);
	void dfs(function<void (Vertice*)> foo);
	void dfsAux(Vertice* v, vector<bool>& visitados, function<void (Vertice*)> foo);

	/**
	 * @brief      Método externo que permite imprimir cada vértice do grafo na tela
	 * usando @c std::cout.
	 *
	 * Declarado como "friend", um método externo tem acesso os dados privados da classe/objeto
	 * mesmo sem estar contido nela.
	 * 
	 * @param[in]  grafo	O grafo a ser impresso.
	 *
	 */
	friend ostream& operator <<(ostream& os, const Grafo& grafo);

};
#endif
