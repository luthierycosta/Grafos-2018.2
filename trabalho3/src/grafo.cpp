#include "../headers/grafo.h"
#include <vector>
#include <exception>
#include <iterator>
#include <iostream>

using namespace std;

Grafo::Grafo(){}

void Grafo::addVertice(Escola e) {
	if (!existeEscola(e.id))
		escolas.push_back(e);
	else
		cout << "Escola [E"<< e.id <<"] já existe no grafo.";	
}

void Grafo::addVertice(Professor p) {
	if (!existeProf(p.id))
		profs.push_back(p);
	else
		cout << "Professor [P"<< p.id <<"] já existe no grafo.";
}

bool Grafo::existeEscola(int id) {
	vector<Escola>::iterator it;
	for (it = escolas.begin(); it != escolas.end(); it++)
		if((*it).id == id)
			return true;

	return false;
}

bool Grafo::existeProf(int id) {
	vector<Professor>::iterator it;
	for (it = profs.begin(); it != profs.end(); it++)
		if((*it).id == id)
			return true;

	return false;
}

Vertice& Grafo::findEscola(int id) {
	vector<Escola>::iterator it;
	for (it = escolas.begin(); it != escolas.end(); it++)
		if((*it).id == id)
			return *it;

	throw "Argumento invalido."; 
}

Vertice& Grafo::findProf(int id) {
	vector<Professor>::iterator it;
	for (it = profs.begin(); it != profs.end(); it++)
		if((*it).id == id)
			return *it;

	throw "Argumento invalido."; 
}

bool Grafo::existeAresta(int id_esc, int id_prof) {
	Vertice* v1 = &findEscola(id_esc);
	Vertice* v2 = &findProf(id_prof);

	return (v1->existeAresta(v2));
}

void Grafo::addAresta(int id_esc, int id_prof) {
	Vertice* v1 = &findEscola(id_esc);
	Vertice* v2 = &findProf(id_prof);
	v1->push_back(v2);
	v2->push_back(v1);
}

void Grafo::removeAresta(int id_esc, int id_prof) {
	if (existeAresta(id_esc, id_prof)) {
		Vertice* v1 = &findEscola(id_esc);
		Vertice* v2 = &findProf(id_prof);
		v1->removeAresta(v2);
		v2->removeAresta(v1);
	}
	else cout << "Aresta ("<< id_esc <<", "<< id_prof << ") não existe." << endl;
}

ostream& operator <<(ostream& os, const Grafo& grafo) {
	os << "\nESCOLAS:\n";
	for(const Escola& v: grafo.escolas)
		os << v;

	os << "\nPROFESSORES:\n";
	for(const Professor& v: grafo.profs)
		os << v;

	os << endl;
	return os;
}
