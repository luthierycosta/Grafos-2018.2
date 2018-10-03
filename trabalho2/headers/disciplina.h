#ifndef _DISCIPLINA_
#define _DISCIPLINA_

#include <string>
#include <iostream>

using namespace std;

class Disciplina {
	string nome;
	int creditos;
	int dificuldade;

public:
	/**
	 * @brief      Constrói um objeto vazio.
	 * 
	 * Não é usado no programa, mas sua ausência no código gerava erro de compilação...
	 */
	Disciplina();

	/**
	 * @brief      Constrói o objeto disciplina com todos os seus atributos.
	 *
	 * @param[in]  _nome         O nome da disciplina.
	 * @param[in]  _creditos     A quantidade de créditos da matéria.
	 * @param[in]  _dificuldade  A dificuldade da matéria.
	 */
	Disciplina(string _nome, int _creditos, int _dificuldade);

	string getNome();
	int getCreditos();
	int getDificuldade();
	
	/**
	 * @brief      Obtém o "peso" da matéria, usado no cálculo dos caminhos críticos do grafo.
	 *
	 * Segundo a especificação, o peso é o produto da qtd. de créditos com a dificuldade da disciplina.
	 * @return     int	O peso da disciplina.
	 */
	int peso();

	/**
	 * @brief      Sobrecarga do operador (==) que permite a comparação de igualdade
	 * entre dois objetos Disciplina.
	 *
	 * @param[in]  lhs   Lado esquerdo
	 * @param[in]  rhs   Lado direito
	 *
	 * @return     true, se o nome da disciplina lhs for igual ao nome da disciplina rhs;
	 * false, caso contrário.
	 */
	friend bool operator==(const Disciplina& lhs, const Disciplina& rhs);

	/**
	 * @brief      Sobrecarga do operador (==) que permite a comparação de igualdade
	 * entre um objeto Disciplina e uma string.
	 *
	 * @param[in]  lhs   Lado esquerdo - disciplina
	 * @param[in]  rhs   Lado direito - string
	 *
	 * @return     true, se o nome da disciplina for igual à string especificada;
	 * false, caso contrário.
	 */
	friend bool operator==(const Disciplina& lhs, const string& rhs);

	/**
	 * @brief      Método que permite se imprimir uma disciplina (ou seja, seu nome)
	 * na tela usando std::cout.
	 */
	friend ostream& operator<<(ostream& os, const Disciplina& disc);
};

#endif