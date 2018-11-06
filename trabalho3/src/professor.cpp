#include "../headers/professor.h"

using namespace std;

Professor::Professor(int _id, int _habilitacoes, int esc1, int esc2, int esc3, int esc4, int esc5) {
	id = _id;
	habilitacoes = _habilitacoes;
	preferencia.push_back(esc1);
	preferencia.push_back(esc2);
	preferencia.push_back(esc3);
	preferencia.push_back(esc4);
	preferencia.push_back(esc5);
	empregado = false;
}

ostream& operator <<(ostream& os, const Professor& prof) {
	os <<"[P"<< prof.id <<"] - habilitações: "<< prof.habilitacoes <<", preferências: ";
	for(int esc: prof.preferencia)
		os <<"("<< esc <<")";

	os << endl;
	return os;
}
