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

using namespace std;

/**
 * @brief      Grafo direcionado, sem pesos nas arestas e com pesos nos vértices,
 * cujos vértices representam disciplinas do curso de Ciência da Computação da UnB.
 * 
 * Usa um vetor público para armazenar seus vértices.
 * 
 * Não há representação do conjunto de arestas. As ligações entre vértices se dão
 * apenas pela manipulação de suas lista de adjacências.
 */
class Grafo {
public:
	vector<Escola> escolas;
	vector<Professor> profs;
	
	Grafo(); 						/** Cria um grafo vazio. */
	
	void addVertice(Escola v); 	/** Adiciona um vértice Escola no vetor respectivo. */
	
	void addVertice(Professor v);	/** Adiciona um vértice Professor no vetor respectivo. */

	/**
	 * @brief      Verifica se uma dada escola está entre as escolas do grafo.
	 * @param[in]  id    O número da escola.
	 * @return     true, caso o vértice exista no grafo; false, caso contrário.
	 */
	bool existeEscola(int id);

	/**
	 * @brief      Verifica se um dado professor está entre os professores do grafo.
	 * @param[in]  id    O número do professor.
	 * @return     true, caso o vértice exista no grafo; false, caso contrário.
	 */
	bool existeProf(int id);

	Vertice& findEscola(int id);	/** Retorna uma referência para a escola de nome informado.*/
	
	Vertice& findProf(int id);		/** Retorna uma referência para o professor de nome informado.*/

	/**
	 * @brief      Checa se existe uma aresta entre escola e professor especificados.
	 *
	 * @param[in]  id_esc  O número da escola.
	 * @param[in]  id_prof  O número do professor.
	 *
	 * @return     true, caso exista uma aresta; false, caso contrário.
	 */
	bool existeAresta(int id_esc, int id_prof);

	/**
	 * @brief      Adiciona uma aresta direcionada entre uma escola e um professor,
	 * se ela ainda não existe.
	 * 
	 * @param[in]  id_esc  O número da escola.
	 * @param[in]  id_prof  O número do professor.
	 */
	void addAresta(int id_esc, int id_prof);

	/**
	 * @brief      Remove a aresta entre escola e professor especificados, caso ela exista.
	 *
	 * @param[in]  id_esc  O número da escola.
	 * @param[in]  id_prof  O número do professor.
	 */
	void removeAresta(int id_esc, int id_prof);

	/**
	 * @brief      Método externo que permite imprimir cada vértice do grafo na tela
	 * usando std::cout.
	 *
	 * Declarado como "friend", um método externo tem acesso os dados privados da classe/objeto
	 * mesmo sem estar contido nela.
	 * 
	 * @param[in]  grafo	O grafo de inteiros a ser impresso.
	 *
	 */
	friend ostream& operator <<(ostream& os, const Grafo& grafo);

};
#endif
