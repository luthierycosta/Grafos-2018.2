#ifndef _PROFESSOR_
#define _PROFESSOR_

#include "vertice.h"
#include <list>
#include <iostream>


using namespace std;

class Professor: public Vertice {
public:
	int habilitacoes;
	list<int> preferencia;		/** Cada posição recebe o número de uma escola. A prioridade é decrescente.*/
	bool empregado;

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