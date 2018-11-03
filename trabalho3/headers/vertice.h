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

/**
 * @brief     Representa um vértice de um grafo.
 */
class Vertice {
public:
	int id;			/** O código da escola ou do professor. */

	/**
	 * Lista de adjacências deste vértice,
	 * onde cada item é um ponteiro ao vértice correspondente no grafo.
	 */
	vector<Vertice*> adjacentes;

	Vertice();		/** Cria um vértice vazio. */

	/**
	 * @brief      Insere um vértice, ou melhor, uma referência para ele, na lista de adjacências.
	 *
	 * @param[in]  v    O ponteiro para o vértice v.
	 */
	void push_back(Vertice* v);

	/**
	 * @brief      Remove a aresta entre este vértice e o vértice v, isto é,
	 * remove v da sua lista de adjacências.
	 *
	 * @param      v     O ponteiro para o vértice v.
	 */
	void removeAresta(Vertice* v);

	/**
	 * @brief      Checa se existe uma aresta entre esse vértice e um outro especificado
	 *
	 * @param[in]  v     Um ponteiro do vértice desejado
	 *
	 * @return     true, caso existe a aresta; false, caso contrário.
	 */
	bool existeAresta(Vertice* v);

	/**
	 * @brief      Checa se o vértice é conectado, ou seja,
	 * se ele contém alguma conexão para um outro vértice.
	 *
	 * Em outras palavras, verifica se sua lista de adjacências é vazia ou não.
	 * 
	 * @return     true, caso o vértice seja conectado; false, caso contrário.
	 */
	bool conectado();

	/**
	 * Retorna o grau do vértice, que é o número de conexões(arestas),
	 * que é o tamanho de sua lista de adjacências.
	 */
	int grau();
};

class Escola: public Vertice {
public:
	vector<int> vagas;
	int vaga_atual;					/** Flag para saber qual das duas vagas estamos analisando.*/

	Escola(int _id);
	void proximaVaga();				/** Pula para a próxima vaga, quando a primeira já estiver preenchida.*/

	/**
	 * @brief      Método externo que permite imprimir as informações da escola
	 * na tela usando std::cout.
	 * 
	 * Declarado como "friend", um método externo tem acesso os dados privados da classe/objeto
	 * mesmo sem estar contido nela.
	 *
	 * @param[in]  v     A escola a ser impressa.
	 */
	friend ostream& operator <<(ostream& os, const Escola& esc);
};

class Professor: public Vertice {
public:
	int habilitacoes;
	vector<int> preferencia;		/** Cada posição recebe o número de uma escola. A prioridade é decrescente.*/

	/**
	 * @brief      Constrói um professor com id, nº de habilitações e lista de escolas especificados.
	 */
	Professor(int _id, int _habilitacoes, int esc1, int esc2, int esc3, int esc4, int esc5);

	/**
	 * @brief      Método externo que permite imprimir as informações do professor
	 * na tela usando std::cout.
	 * 
	 * Declarado como "friend", um método externo tem acesso os dados privados da classe/objeto
	 * mesmo sem estar contido nela.
	 *
	 * @param[in]  v     O professor a ser impresso.
	 */
	friend ostream& operator <<(ostream& os, const Professor& prof);
};

#endif
