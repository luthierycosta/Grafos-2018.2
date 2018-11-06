#include "../headers/grafo.h"
#include <vector>
#include <utility>

using namespace std;

void Grafo::emparelhamento(int max_pares){

	int qtd_pares = 0;
	while(qtd_pares < max_pares) {

		for(Professor* prof_atual: profs) {
			if(prof_atual->preferencia.empty())	// se não sobrou escolas na lista de preferências do prof_atual, não tem nada a fazer
				continue;

			Escola* esc_atual = (Escola*)findEscola(prof_atual->preferencia.front());

			if(!esc_atual->cheia()) {

				if(esc_atual->vagas.size() == 1) {

					if(prof_atual->habilitacoes >= esc_atual->vagas[0]) {
						esc_atual->contratado1 = prof_atual;
						qtd_pares++;
					}
				}
				else if(esc_atual->vagas.size() == 2) {

					if(esc_atual->contratado1) {
						if(prof_atual->habilitacoes > esc_atual->contratado1->habilitacoes) {
							esc_atual->contratado1 = prof_atual;
						}
					}
					else if(esc_atual->contratado2) {
						if(prof_atual->habilitacoes > esc_atual->contratado2->habilitacoes) {
							esc_atual->contratado2 = prof_atual;
						}
					}
					else if(prof_atual->habilitacoes >= esc_atual->vagas[0]) {
						esc_atual->contratado1 = prof_atual;
						qtd_pares++;
					}
					else if(prof_atual->habilitacoes >= esc_atual->vagas[0]) {
						esc_atual->contratado2 = prof_atual;
						qtd_pares++;
					}
				}
			}
			else {
				if(esc_atual->vagas.size() == 1) {
					for(Professor* p1: esc_atual->candidatos1) {
						if(esc_atual->contratado1->habilitacoes >= p1->habilitacoes)
							p1->preferencia.remove(esc_atual->id);
					}
				}
				else if(esc_atual->vagas.size() == 2) {
					for(Professor* p1: esc_atual->candidatos1) {
						if(esc_atual->contratado1->habilitacoes >= p1->habilitacoes) {
							p1->preferencia.remove(esc_atual->id);
						}
					}
					for(Professor* p2: esc_atual->candidatos2) {
						if(esc_atual->contratado2->habilitacoes >= p2->habilitacoes)
							p2->preferencia.remove(esc_atual->id);
					}
				}
			}

		}
	}
}