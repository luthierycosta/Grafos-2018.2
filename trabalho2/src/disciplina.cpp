#include "../headers/disciplina.h"
#include <string>
#include <iostream>

using namespace std;

Disciplina::Disciplina(){}

Disciplina::Disciplina(string _nome, int _creditos, int _dificuldade, int _posicao) {
	this->nome = _nome;
	this->creditos = _creditos;
	this->dificuldade = _dificuldade;
	this->posicao = _posicao;
}

string Disciplina::getNome(){
	return this->nome;
}

int Disciplina::getCreditos(){
	return this->creditos;
}

int Disciplina::getDificuldade(){
	return this->dificuldade;
}

int Disciplina::getPosicao(){
	return this->posicao;
}

int Disciplina::peso(){
	return (this->creditos * this->dificuldade);
}

bool operator==(const Disciplina& lhs, const Disciplina& rhs) {
	return (lhs.nome == rhs.nome);
}

bool operator==(const Disciplina& lhs, const string& rhs) {
	return (lhs.nome == rhs);
}

ostream& operator<<(ostream& os, const Disciplina& disc) {
	return os << disc.nome;
}
