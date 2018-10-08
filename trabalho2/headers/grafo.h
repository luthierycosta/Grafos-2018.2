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
#include "disciplina.h"
#include <vector>
#include <string>
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
	/**
	 * Representa o conjunto de vértices do grafo.
	 */
	vector<Vertice> vertices;
	
	/**
	 * @brief      Cria um grafo vazio.
	 */
	Grafo();

	/**
	 * @brief      Adiciona um vértice de tipo Disciplina no vetor, onde os parâmetros
	 * são os parâmetros do construtor de Disciplina.
	 *
	 * @param[in]  nome         O nome da disciplina.
	 * @param[in]  creditos     A qtd. de créditos da disciplina.
	 * @param[in]  dificuldade  A dificuldade da disciplina.
	 */
	void addVertice(string nome, int creditos, int dificuldade, int posicao);

	/**
	 * @brief      Verifica se uma dada disciplina está no grafo buscando pelo seu nome.
	 *
	 * @param[in]  nome    O nome da disciplina.
	 *
	 * @return     true, caso o vértice exista no grafo; false, caso contrário.
	 */
	bool existeVertice(string nome);

	/**
	 * @brief      Retorna uma referência para o vértice de nome informado.
	 *
	 * @param[in]  nome    O nome da disciplina.
	 *
	 * @return     O vértice encontrado, caso exista. Lança uma exceção, caso contrário.
	 */
	Vertice& getVertice(string nome);

	/**
	 * @brief      Adiciona uma aresta direcionada do vértice a para o vértice b,
	 * se ela ainda não existe.
	 * 
	 * @param[in]  nome_a  O nome da disciplina a.
	 * @param[in]  nome_b  O nome da disciplina b.
	 */
	void addAresta(string nome_a, string nome_b);

	/**
	 * @brief      Remove a aresta entre o vértice a e o vértice b, caso ela exista.
	 *
	 * @param[in]  nome_a  O nome da disciplina a.
	 * @param[in]  nome_b  O nome da disciplina b.
	 */
	void removeAresta(string nome_a, string nome_b);

	/**
	 * @brief      Checa se existe uma aresta entre dois vértices a e b buscando pelos seus nomes.
	 *
	 * @param[in]  nome_a  O nome da disciplina a.
	 * @param[in]  nome_b  O nome da disciplina b.
	 *
	 * @return     true, caso exista uma aresta; false, caso contrário.
	 */
	bool existeAresta(string nome_a, string nome_b);

	/**
	 * @brief      Recupera o grau do grafo, isto é,
	 * o maior grau entre seus vértices.
	 *
	 * @return     int	O valor do grau.
	 */
	int grau();

	/**
	 * @brief      Obtém o grafo inverso deste grafo.
	 * 
	 * Para cada aresta (v, w) de um grafo direcionado G, seu inverso terá a aresta (w, v).
	 *
	 * @return     O grafo inverso.
	 */
	Grafo inverso();

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
