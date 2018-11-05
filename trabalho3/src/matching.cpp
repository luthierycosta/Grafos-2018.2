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
	vector<int> professor(grafo.profs.size(), -1), escola(grafo.escolas.size(), -1);
	vector<pair<int, int> > pares(grafo.escolas.size());
	int esc_atual = 0, count=0;

	while(soma(professor) < 100){

		for(int i=0; i<professor.size(); i++ ){//percorre todos os professores
			for(int j=0; j<=4; j++){//percorre a lista de preferencias do professor atual
				esc_atual = grafo.profs[i].preferencia[j];
				//cout << "esc_atual: " << grafo.profs[i].preferencia[j] << endl << "grafo.escolas[esc_atual].vagas.size(): " << grafo.escolas[esc_atual].vagas.size() << endl;
				//cout << "escola atual: " << esc_atual << endl << "prof atual: " << i+1 << endl << endl;
				//cout << "pares[esc_atual].first: " << pares[esc_atual].first << endl << "pares[esc_atual].second: " << pares[esc_atual].second << endl << "grafo.escolas[esc_atual].vaga1: " << grafo.escolas[esc_atual].vaga1 << endl << "grafo.escolas[esc_atual].vaga2: " << grafo.escolas[esc_atual].vaga2 << endl << "grafo.profs[i].habilitacoes: " << grafo.profs[i].habilitacoes << endl;
				if(grafo.escolas[esc_atual].vagas.size() == 2){//caso tenha duas vagas, não necessariamente livres				
					if(escola[esc_atual] < 1){//caso tenha vagas livres
						if(pares[esc_atual].first == 0 && grafo.escolas[esc_atual].vaga1 <= grafo.profs[i].habilitacoes){//caso a vaga livre seja a primeira e eu seja capacitado
							professor[i] = 1;
							escola[esc_atual]++;
							pares[esc_atual].first = i+1;
							//cout << "caso duas vagas, primeira livre" << endl<< endl << endl;
							//cout << "pares[esc_atual].first depois: " << pares[esc_atual].first << endl << "pares[esc_atual].second depois: " << pares[esc_atual].second << endl;
							break;
						}else if(pares[esc_atual].second == 0 && grafo.escolas[esc_atual].vaga2 <= grafo.profs[i].habilitacoes){//caso a vaga livre seja a segunda e eu seja capacitado
							professor[i] = 1;
							escola[esc_atual]++;
							pares[esc_atual].second = i+1;
							//cout << "caso duas vagas, segunda livre" << endl<< endl << endl;
							//cout << "pares[esc_atual].first depois: " << pares[esc_atual].first << endl << "pares[esc_atual].second depois: " << pares[esc_atual].second << endl;
							break;
						}
					}else if(escola[esc_atual] = 1){//caso nao tenha vagas livres
						if(grafo.escolas[esc_atual].vaga1 <= grafo.profs[i].habilitacoes && grafo.profs[pares[esc_atual].first].habilitacoes < grafo.profs[i].habilitacoes){//vendo se é mais qualificado doq o prof atual da primeira vaga
							professor[pares[esc_atual].first]--;
							pares[esc_atual].first = i+1;
							professor[i]++;
							//cout << "caso duas vagas, nenhuma livre mas trocou primeira" << endl<< endl << endl;
							//cout << "pares[esc_atual].first depois: " << pares[esc_atual].first << endl << "pares[esc_atual].second depois: " << pares[esc_atual].second << endl;
							break;
						}else if(grafo.escolas[esc_atual].vaga2 <= grafo.profs[i].habilitacoes && grafo.profs[pares[esc_atual].second].habilitacoes < grafo.profs[i].habilitacoes){//vendo se é mais qualificado doq o prof atual da segunda vaga
							professor[pares[esc_atual].second]--;
							pares[esc_atual].second = i+1;
							professor[i]++;
							//cout << "caso duas vagas, nenhuma livre mas trocou segunda" << endl<< endl << endl;		
							//cout << "pares[esc_atual].first depois: " << pares[esc_atual].first << endl << "pares[esc_atual].second depois: " << pares[esc_atual].second << endl;					
							break;
						}
					}
				}else if(grafo.escolas[esc_atual].vagas.size() == 1){//caso só tenha uma vaga, não necessariamente livre
					if(escola[esc_atual] < 1){//caso ela esteja livre
						if(grafo.escolas[esc_atual].vaga1 <= grafo.profs[i].habilitacoes){//caso eu seja capacitado pra essa vaga
							professor[i] = 1;
							escola[esc_atual]++;
							escola[esc_atual]++;//incrementar 2x pois -1 == totalmente vazia, 0 == uma vaga preenchida e 1 == totalmente preenchida. por ter só uma vaga, ao se preencher já está totalmente preenchida
							pares[esc_atual].first = i+1;
							//cout << "caso só uma vaga, ela livre" << endl<< endl << endl;	
							//cout << "pares[esc_atual].first depois: " << pares[esc_atual].first << endl << "pares[esc_atual].second depois: " << pares[esc_atual].second << endl;				
							break;
						}
					}else if(escola[esc_atual] = 1){//caso ela não esteja livre
						if(grafo.escolas[esc_atual].vaga1 <= grafo.profs[i].habilitacoes && grafo.profs[pares[esc_atual].first].habilitacoes < grafo.profs[i].habilitacoes){//vendo se é mais qualificado doq o prof atual da vaga
							professor[pares[esc_atual].first]--;
							pares[esc_atual].first = i+1;
							professor[i]++;
							//cout << "caso só uma vaga ocupada, mas trocou" << endl<< endl << endl;	
							//cout << "pares[esc_atual].first depois: " << pares[esc_atual].first << endl << "pares[esc_atual].second depois: " << pares[esc_atual].second << endl;						
							break;
						}
					}
				}
			}
		}
	}
	return pares;
}
