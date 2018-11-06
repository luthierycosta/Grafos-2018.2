#include "../headers/escola.h"

using namespace std;

Escola::Escola(int _id, int _vaga1, int _vaga2) {
	id = _id;
	vagas.push_back(_vaga1);
	vagas.push_back(_vaga2);
	contratado1 = nullptr;
	contratado2 = nullptr;
}

Escola::Escola(int _id, int _vaga1) {
	id = _id;
	vagas.push_back(_vaga1);
	contratado1 = nullptr;
	contratado2 = nullptr;
}

bool Escola::cheia() {
	return (grau() >= vagas.size());		// grau, aqui, é o número de professores contratados
}

ostream& operator <<(ostream& os, const Escola& esc) {
	os <<"[E"<< esc.id <<"] - vagas: "<< esc.vagas.size() <<", requerindo ";
	for(int habt: esc.vagas)
		os <<"("<< habt<<")";

	os <<" habilitações respectivamente."<< endl;
	return os;
}