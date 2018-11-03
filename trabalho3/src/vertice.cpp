#include "../headers/vertice.h"
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

Vertice::Vertice() {}

void Vertice::push_back(Vertice* v) {
	adjacentes.push_back(v);
}

void Vertice::removeAresta(Vertice* v) {
	adjacentes.erase(remove(adjacentes.begin(), adjacentes.end(), v), adjacentes.end());
}

bool Vertice::existeAresta(Vertice* v) {
	for (Vertice* adj: adjacentes)
		if (adj->id == v->id)
			return true;

	return false;
}

bool Vertice::conectado() {
	return (adjacentes.size() != 0);
}

int Vertice::grau() {
	return adjacentes.size();
}

/*---------------------------------------------------------------------------------------*/

Escola::Escola(int _id, int _vaga1, int _vaga2) {
	id = _id;
	vagas.push_back(_vaga1);
	vagas.push_back(_vaga2);
}

Escola::Escola(int _id, int _vaga1) {
	id = _id;
	vagas.push_back(_vaga1);
}

void Escola::proximaVaga() {
	if(vaga_atual == 1)
		vaga_atual = 0;
	else
		vaga_atual++;
}

ostream& operator <<(ostream& os, const Escola& esc) {
	os <<"[E"<< esc.id <<"] - vagas: "<< esc.vagas.size() <<", requerindo ";
	for(int habt: esc.vagas)
		os <<"("<< habt<<")";

	os <<" habilitações respectivamente."<< endl;
	return os;
}
/*---------------------------------------------------------------------------------------*/

Professor::Professor(int _id, int _habilitacoes, int esc1, int esc2, int esc3, int esc4, int esc5) {
	id = _id;
	habilitacoes = _habilitacoes;
	preferencia.push_back(esc1);
	preferencia.push_back(esc2);
	preferencia.push_back(esc3);
	preferencia.push_back(esc4);
	preferencia.push_back(esc5);
}

ostream& operator <<(ostream& os, const Professor& prof) {
	os <<"[P"<< prof.id <<"] - habilitações: "<< prof.habilitacoes <<", preferências: ";
	for(int esc: prof.preferencia)
		os <<"("<< esc <<")";

	os << endl;
	return os;
}

