#ifndef _ESCOLA_
#define _ESCOLA_

#include "vertice.h"
#include "professor.h"
#include <vector>
#include <list>
#include <iostream>

using namespace std;


class Escola: public Vertice {
public:
	vector<int> vagas;
	list<Professor*> candidatos1;
	list<Professor*> candidatos2;
	Professor* contratado1;
	Professor* contratado2;
	Escola(int _id, int _vaga1, int _vaga2);
	Escola(int _id, int _vaga1);
	//void contrate(Professor p);
	bool cheia();


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

#endif