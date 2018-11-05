#include "../headers/matching.h"
#include "../headers/grafo.h"
#include <bits/stdc++.h>

using namespace std;

int soma(vector<int> vetor){
	int soma=0;
	for(int i=0; i<vetor.size(); i++){
		soma = soma+vetor[i];
	}
	return soma;
}

vector<pair<int, int> > matching(Grafo& grafo){
	vector<int> professor(-1, grafo.profs.size()+1), escola(-1, grafo.escolas.size()+1);
	vector<pair<int, int> > pares(grafo.escolas.size()+1);
	int esc_atual = 0;
	while(soma(professor) < 0){
		for(int i=1; i<=professor.size(); i++ ){//percorre todos os professores
			for(int j=5; j>0; j--){//percorre a lista de preferencias do professor atual
				esc_atual = grafo.profs[i].preferencia[j];
				if(grafo.escolas[esc_atual].vagas.size() == 2){//caso tenha duas vagas, não necessariamente livres
					if(escola[esc_atual] < 1){//caso tenha vagas livres
						if(pares[esc_atual].first != 0 && grafo.escolas[esc_atual].vaga1 <= grafo.profs[i].habilitacoes){//caso a vaga livre seja a primeira e eu seja capacitado
							professor[i] = 1;
							escola[esc_atual]++;
							pares[esc_atual].first = i;
							break;
						}else if(pares[esc_atual].second != 0 && grafo.escolas[esc_atual].vaga1 <= grafo.profs[i].habilitacoes){//caso a vaga livre seja a segunda e eu seja capacitado
							professor[i] = 1;
							escola[esc_atual]++;
							pares[esc_atual].second = i;
							break;
						}
					}else if(escola[esc_atual] = 1){//caso nao tenha vagas livres
						if(grafo.escolas[esc_atual].vaga1 <= grafo.profs[i].habilitacoes && grafo.profs[pares[esc_atual].first].habilitacoes < grafo.profs[i].habilitacoes){//vendo se é mais qualificado doq o prof atual da primeira vaga
							professor[pares[esc_atual].first]--;
							pares[esc_atual].first = i;
							professor[i]++;
							break;
						}else if(grafo.escolas[esc_atual].vaga2 <= grafo.profs[i].habilitacoes && grafo.profs[pares[esc_atual].second].habilitacoes < grafo.profs[i].habilitacoes){//vendo se é mais qualificado doq o prof atual da segunda vaga
							professor[pares[esc_atual].second]--;
							pares[esc_atual].second = i;
							professor[i]++;
							break;
						}
					}
				}else if(grafo.escolas[esc_atual].vagas.size() < 2){//caso só tenha uma vaga, não necessariamente livre
					if(escola[esc_atual] < 1){//caso ela esteja livre
						if(grafo.escolas[esc_atual].vaga1 <= grafo.profs[i].habilitacoes){//caso eu seja capacitado pra essa vaga
							professor[i] = 1;
							escola[esc_atual]++;
							escola[esc_atual]++;//incrementar 2x pois -1 == totalmente vazia, 0 == uma vaga preenchida e 1 == totalmente preenchida. por ter só uma vaga, ao se preencher já está totalmente preenchida
							pares[esc_atual].first = i;
							break;
						}
					}else if(escola[esc_atual] = 1){//caso ela não esteja livre
						if(grafo.escolas[esc_atual].vaga1 <= grafo.profs[i].habilitacoes && grafo.profs[pares[esc_atual].first].habilitacoes < grafo.profs[i].habilitacoes){//vendo se é mais qualificado doq o prof atual da vaga
							professor[pares[esc_atual].first]--;
							pares[esc_atual].first = i;
							professor[i]++;
							break;
						}
					}
				}
			}
		}
	}
	return pares;
}
