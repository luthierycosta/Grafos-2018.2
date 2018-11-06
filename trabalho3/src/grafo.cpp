#include "../headers/grafo.h"
#include <vector>
#include <exception>
#include <iostream>

using namespace std;

Grafo::Grafo(){}

Grafo::~Grafo() {
	for(Escola* esc: escolas) delete esc;
	for(Professor* p: profs) delete p;
}

void Grafo::addVertice(Escola* e) {
	if (!existeEscola(e->id))
		escolas.push_back(e);
	else
		cout << "Escola [E"<< e->id <<"] já existe no grafo.";	
}

void Grafo::addVertice(Professor* p) {
	if (!existeProf(p->id))
		profs.push_back(p);
	else
		cout << "Professor [P"<< p->id <<"] já existe no grafo.";
}

bool Grafo::existeEscola(int id) {
	for (Escola* esc: escolas)
		if(esc->id == id)
			return true;

	return false;
}

bool Grafo::existeProf(int id) {
	for (Professor* p: profs)
		if(p->id == id)
			return true;

	return false;
}

Vertice* Grafo::findEscola(int id) {
	for (Escola* esc: escolas)
		if(esc->id == id)
			return esc;

	throw "Argumento invalido."; 
}

Vertice* Grafo::findProf(int id) {
	for (Professor* p: profs)
		if(p->id == id)
			return p;

	throw "Argumento invalido."; 
}

bool Grafo::existeAresta(int id_esc, int id_prof) {
	Vertice* v1 = findEscola(id_esc);
	Vertice* v2 = findProf(id_prof);

	return (v1->existeAresta(v2));
}

void Grafo::addAresta(int id_esc, int id_prof) {
	Vertice* v1 = findEscola(id_esc);
	Vertice* v2 = findProf(id_prof);
	v1->push_back(v2);
	v2->push_back(v1);
}

void Grafo::removeAresta(int id_esc, int id_prof) {
	if (existeAresta(id_esc, id_prof)) {
		Vertice* v1 = findEscola(id_esc);
		Vertice* v2 = findProf(id_prof);
		v1->removeAresta(v2);
		v2->removeAresta(v1);
	}
	else cout << "Aresta ("<< id_esc <<", "<< id_prof << ") não existe." << endl;
}

void Grafo::setCandidatos() {

	for(Professor* prof: profs) {
		for(int esc_id: prof->preferencia) {
			Escola* esc = (Escola*)findEscola(esc_id);

			if(esc->vagas.size() == 1) {
				if(prof->habilitacoes >= esc->vagas[0])
					esc->candidatos1.push_back(prof);
			}
			else if(esc->vagas.size() == 2) {
				if(prof->habilitacoes >= esc->vagas[0])
					esc->candidatos1.push_back(prof);
				if(prof->habilitacoes >= esc->vagas[1])
					esc->candidatos2.push_back(prof);
			}
		}
	}
}

ostream& operator <<(ostream& os, const Grafo& grafo) {
	os << "\nESCOLAS:\n";
	for(Escola* v: grafo.escolas)
		os << *v;

	os << "\nPROFESSORES:\n";
	for(Professor* v: grafo.profs)
		os << *v;

	os << endl;
	return os;
}
