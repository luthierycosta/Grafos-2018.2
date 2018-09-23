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
#include <string>

using namespace std;

/**
 * @brief      Classe Grafo, que usa um vetor público para armazenar seus vértices.
 * 
 * Não há representação do conjunto de arestas. As ligações entre vértices se dão
 * apenas pela manipulação de suas lista de adjacências.
 */
class Grafo {
public:
	/**
	 * Representa o conjunto de vértices do grafo.
	 */
	vector<Vertice> vertices;
	
	/**
	 * @brief      Cria um grafo vazio.
	 */
	Grafo();

	/**
	 * Cria um grafo com uma dada quantidade de vértices n,
	 * nomeados de 1 a n.
	 * 
	 * @param[in]  n	A quantidade de vértices desejada.
	 */
	Grafo(int n);

	/**
	 * @brief      Adiciona um vértice no vetor.
	 *
	 * @param[in]  id    O id do vértice
	 */
	void addVertice(int id);

	/**
	 * @brief      Adiciona uma aresta entre os vértices a e b, se ela já não existir.
	 *
	 * @param[in]  id_a  O id do vértice a
	 * @param[in]  id_b  O id do vértice b
	 */
	void addAresta(int id_a, int id_b);

	/**
	 * @brief      Checa se existe uma aresta entre dois vértices a e b.
	 *
	 * @param[in]  id_a  O id do vértice a
	 * @param[in]  id_b  O id do vértice b
	 *
	 * @return     true, caso exista uma aresta; false, caso contrário.
	 */

	bool existeAresta(int id_a, int id_b);

	/**
	 * @brief      Retorna uma referência para o vértice de id (id).
	 *
	 * @param[in]  id    O id desejado
	 *
	 * @return     O vértice encontrado, caso exista. Lança uma exceção, caso contrário.
	 */
	Vertice& getVertice(int id);

	/**
	 * @brief      Checa se o grafo é conectado, isto é,
	 * checa se cada vértices possui ao menos uma ligação com qualquer outro.
	 *
	 * @return     true, se o grafo é conectado; false, caso contrário.
	 */
	bool conectado();

	/**
	 * @brief      Recupera o grau do grafo, isto é,
	 * o maior grau entre seus vértices.
	 *
	 * @return     int	O valor do grau.
	 */
	int grau();



	/**
	 * @brief      Imprime o grafo na tela.
	 * 
	 * Mostra cada vértice e sua respectiva lista de adjacências.
	 */
	void imprime();

	/**
	 * @brief      Calcula o coeficiente de aglomeração médio deste grafo.
	 * 
	 * O coeficiente de aglomeração médio de um grafo é a média aritmética
	 * dos coef. de aglomeração de todos os seus vértices.
	 *
	 */
	double coefAglomeracao();

};
#endif