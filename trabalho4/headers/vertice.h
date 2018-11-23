/**
 * Arquivo-cabeçalho contendo as declarações da classe Vértice
 * e seus atributos e métodos.
 */
#ifndef _VERTICE_H_
#define _VERTICE_H_

#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Vertice {		/** Representa um vértice de um grafo. */
public:
	int id;			/** O código/nome/valor do vértice. */

	/**
	 * Lista de adjacências deste vértice,
	 * onde cada item é um ponteiro ao vértice correspondente no grafo.
	 */
	vector<Vertice*> adjacentes;

	Vertice(int id);		/** Cria um vértice com o id especificado. */

	void push_back(Vertice* v);	/** Insere um ponteiro para o vértice v na lista de adjacências. */

	void removeAresta(Vertice* v); /** Remove a aresta (this, v), isto é, remove v da lista de adjacência desse vértice.*/

	bool existeAresta(Vertice* v); /** Checa se existe aresta entre esse vértice e o vértice v. */

	bool conectado();	/** Checa se esse vértice contém alguma aresta para algum vértice qualquer.*/

	int grau();			/** Retorna o grau do vértice, que é o número de conexões(arestas).*/

	/**
	 * @brief      Método externo que permite imprimir o vértice e sua lista de adjacências
	 * na tela usando @c std::cout.
	 * 
	 * Declarado como "friend", um método externo tem acesso os dados privados da classe/objeto
	 * mesmo sem estar contido nela.
	 *
	 * @param[in]  v     O vértice a ser impresso.
	 */
	friend ostream& operator <<(ostream& os, const Vertice& v);
};

#endif
