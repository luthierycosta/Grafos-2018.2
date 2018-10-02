#ifndef _DISCIPLINA_
#define _DISCIPLINA_

#include <string>

using namespace std;

class Disciplina {
	string nome;
	int creditos;
	int dificuldade;

public:
	string getNome();
	int getCredito();
	int getDificuldade();
	int peso();
}

/**
 * @brief      Gets the nome.
 *
 * @return     The nome.
 */
string Disciplina::getNome(){
	return this->nome	
}
/**
 * @brief      { function_description }
 *
 * @return     { description_of_the_return_value }
 */
int Disciplina::getCreditos(){
	return this->creditos;
}

/**
 * @brief      Gets the dificuldade.
 *
 * @return     The dificuldade.
 */
int Disciplina::getDificuldade(){
	return this->dificuldade;
}

/**
 * @brief      Gets the peso.
 *
 * @return     The peso.
 */
int Disciplina::peso(){
	return (this->creditos * this->dificuldade);
}

#endif