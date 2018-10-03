#include "../headers/disciplina.h"
#include <string>
#include <iostream>

using namespace std;

Disciplina::Disciplina(){}

Disciplina::Disciplina(string _nome, int _creditos, int _dificuldade) {
	this->nome = _nome;
	this->creditos = _creditos;
	this->dificuldade = _dificuldade;
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