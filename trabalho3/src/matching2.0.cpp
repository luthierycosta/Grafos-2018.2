#include "../headers/grafo.h"
#include <vector>
#include <utility>

using namespace std;

vector<pair<int, int> > Grafo::emparelhamento(int max_pares){

	int qtd_pares = 0;
	while(qtd_pares < max_pares) {

		for(Professor prof_atual: profs) {
			if(prof_atual.preferencia.empty())	// se não sobrou escolas na lista de preferências do prof_atual, não tem nada a fazer
				continue;

			Escola esc_atual = findEscola(prof_atual.preferencia[0]);

			if(!esc_atual.cheia()) {								// se não tá cheia, basta estar capacitado e pronto
				if(prof_atual.habilitacoes >= esc_atual.vagas[0]) {	// checa se preenche os requisitos da primeira vaga
					addAresta(esc_atual, prof_atual);
				}
				else if(esc_atual.vagas.size() == 2) {						// caso não preencha, veja se há uma segunda vaga
					if(prof_atual.habilitacoes >= esc_atual.vagas[1])		// antes de tentar entrar nela
						addAresta(esc_atual, prof_atual);
				}
			}
			else {													// nesse caso, a escola está cheia; tente entrar no lugar de quem já está
				if(prof_atual.habilitacoes > esc_atual.adjacentes[0].habilitacoes) {	// adjacentes = contratados
					removeAresta(esc_atual, esc_atual.adjacentes[0]);					// índice 0: primeira vaga
					addAresta(esc_atual, prof_atual);
				}
				else if (esc_atual.vagas.size() == 2) {							// não conseguiu a primeira? veja se tem 2 vagas
					if(prof_atual.habilitacoes > esc_atual.adjacentes[1].habilitacoes) {
						removeAresta(esc_atual, esc_atual.adjacentes[1]);					// índice 1: segunda vaga
						addAresta(esc_atual, prof_atual);
					}
				}
			}

			if (esc_atual.cheia()) {		// agora vamos limpar as opções de quem não tem mais chance de entrar na escola, no caso de ela estar cheia
				for()
					//.........
			}
		}
	}
}