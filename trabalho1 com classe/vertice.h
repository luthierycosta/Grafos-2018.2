/**
 * Arquivo-cabeçalho contendo as declarações da classe Vértice
 * e seus atributos e métodos.
 */
#include <vector>

using namespace std;

/**
 * @brief      Classe Vértice, que representa um vértice em um grafo.
 */
class Vertice {
public:
	/**
	 * O 'nome' ou 'valor' do vértice.
	 */
	int id;

	/**
	 * Lista de adjacências deste vértice,
	 * onde cada valor é o id do vértice correspondente.
	 */
	vector<int> adjacentes;

	/**
	 * @brief      Cria um vértice com o id especificado.
	 *
	 * @param[in]  new_id	O id
	 */
	Vertice(int new_id);

	/**
	 * @brief      Insere um vértice, ou seja, seu id, na lista de adjacências.
	 *
	 * @param[in]  v    O id do vértice
	 */
	void push_back(int v);

	/**
	 * @brief      Checa se existe uma aresta entre esse vértice e um outro especificado
	 *
	 * @param[in]  v     O id do vértice desejado
	 *
	 * @return     true, caso existe a aresta; false, caso contrário.
	 */
	bool existeAresta(int v);

	/**
	 * @brief      Checa se o vértice é conectado, ou seja,
	 * se ele contém alguma conexão para um outro vértice.
	 *
	 * Em outras palavras, verifica se sua lista de adjacências é vazia ou não.
	 * 
	 * @return     true, caso o vértice seja conectado; false, caso contrário.
	 */
	bool conectado();

	/**
	 * Retorna o grau do vértice, que é o número de conexões(arestas),
	 * que é o tamanho de sua lista de adjacências.
	 */
	int grau();

	/**
	 * @brief      Imprime na tela os valores do vértice e de sua lista de adjacências.
	 */
	void imprime();

};