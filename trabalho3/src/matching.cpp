#include "../headers/grafo.h"
#include <vector>
#include <utility>

using namespace std;

int soma(vector<int>& vetor){
	int soma=0;
	for(int i=0; i<(int)vetor.size(); i++){
		soma += vetor[i];
	}
	return soma;
}

vector<pair<int, int> > Grafo::matching(){

	vector<int> escola(this->escolas.size(), -1);
	vector<pair<int, int> > pares(this->escolas.size());
	int esc_atual = 0, qtd_pares = 0;

	while(qtd_pares < 70){	// como terão no máximo 70 professores contratados, 70(1) + 30(-1) = 40

		for(int i=0; i<(int)profs.size(); i++ ){//percorre todos os professores
			if(profs[i].empregado) continue;		// se ele já está empregado, não precisa procurar outra escola

			for(int j=0; j<=4; j++){//percorre a lista de preferencias do professor atual
				esc_atual = this->profs[i].preferencia[j];
				//cout << "esc_atual: " << this->profs[i].preferencia[j] << endl << "this->escolas[esc_atual].vagas.size(): " << this->escolas[esc_atual].vagas.size() << endl;
				//cout << "escola atual: " << esc_atual << endl << "prof atual: " << i+1 << endl << endl;
				//cout << "pares[esc_atual].first: " << pares[esc_atual].first << endl << "pares[esc_atual].second: " << pares[esc_atual].second << endl << "this->escolas[esc_atual].vagas[0]: " << this->escolas[esc_atual].vagas[0] << endl << "this->escolas[esc_atual].vagas[1]: " << this->escolas[esc_atual].vagas[1] << endl << "this->profs[i].habilitacoes: " << this->profs[i].habilitacoes << endl;
				if(this->escolas[esc_atual].vagas.size() == 2){//caso tenha duas vagas, não necessariamente livres				
					if(escola[esc_atual] < 1){//caso tenha vagas livres
						if(pares[esc_atual].first == 0 && this->escolas[esc_atual].vagas[0] <= this->profs[i].habilitacoes){//caso a vaga livre seja a primeira e eu seja capacitado
							profs[i].empregado = true;
							escola[esc_atual]++;
							pares[esc_atual].first = i+1;
							qtd_pares++;
							//cout << "caso duas vagas, primeira livre" << endl<< endl << endl;
							//cout << "pares[esc_atual].first depois: " << pares[esc_atual].first << endl << "pares[esc_atual].second depois: " << pares[esc_atual].second << endl;
							break;
						}else if(pares[esc_atual].second == 0 && this->escolas[esc_atual].vagas[1] <= this->profs[i].habilitacoes){//caso a vaga livre seja a segunda e eu seja capacitado
							profs[i].empregado = true;
							escola[esc_atual]++;
							pares[esc_atual].second = i+1;
							qtd_pares++;
							//cout << "caso duas vagas, segunda livre" << endl<< endl << endl;
							//cout << "pares[esc_atual].first depois: " << pares[esc_atual].first << endl << "pares[esc_atual].second depois: " << pares[esc_atual].second << endl;
							break;
						}
					}else if(escola[esc_atual] == 1){//caso nao tenha vagas livres
						if(this->escolas[esc_atual].vagas[0] <= this->profs[i].habilitacoes && this->profs[pares[esc_atual].first].habilitacoes < this->profs[i].habilitacoes){//vendo se é mais qualificado doq o prof atual da primeira vaga
							profs[pares[esc_atual].first].empregado = false;
							pares[esc_atual].first = i+1;
							profs[i].empregado = true;
							//cout << "caso duas vagas, nenhuma livre mas trocou primeira" << endl<< endl << endl;
							//cout << "pares[esc_atual].first depois: " << pares[esc_atual].first << endl << "pares[esc_atual].second depois: " << pares[esc_atual].second << endl;
							break;
						}else if(this->escolas[esc_atual].vagas[1] <= this->profs[i].habilitacoes && this->profs[pares[esc_atual].second].habilitacoes < this->profs[i].habilitacoes){//vendo se é mais qualificado doq o prof atual da segunda vaga
							profs[pares[esc_atual].second].empregado = false;
							pares[esc_atual].second = i+1;
							profs[i].empregado = true;
							//cout << "caso duas vagas, nenhuma livre mas trocou segunda" << endl<< endl << endl;		
							//cout << "pares[esc_atual].first depois: " << pares[esc_atual].first << endl << "pares[esc_atual].second depois: " << pares[esc_atual].second << endl;					
							break;
						}
					}
				}else if(this->escolas[esc_atual].vagas.size() == 1){//caso só tenha uma vaga, não necessariamente livre
					if(escola[esc_atual] < 1){//caso ela esteja livre
						if(this->escolas[esc_atual].vagas[0] <= this->profs[i].habilitacoes){//caso eu seja capacitado pra essa vaga
							profs[i].empregado = true;
							escola[esc_atual]++;
							escola[esc_atual]++;//incrementar 2x pois -1 == totalmente vazia, 0 == uma vaga preenchida e 1 == totalmente preenchida. por ter só uma vaga, ao se preencher já está totalmente preenchida
							qtd_pares++;
							pares[esc_atual].first = i+1;
							//cout << "caso só uma vaga, ela livre" << endl<< endl << endl;	
							//cout << "pares[esc_atual].first depois: " << pares[esc_atual].first << endl << "pares[esc_atual].second depois: " << pares[esc_atual].second << endl;				
							break;
						}
					}else if(escola[esc_atual] == 1){//caso ela não esteja livre
						if(this->escolas[esc_atual].vagas[0] <= this->profs[i].habilitacoes && this->profs[pares[esc_atual].first].habilitacoes < this->profs[i].habilitacoes){//vendo se é mais qualificado doq o prof atual da vaga
							profs[pares[esc_atual].first].empregado = false;	
							pares[esc_atual].first = i+1;
							profs[i].empregado = true;
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
