/**
 * Arquivo-cabeçalho contendo a declaração das funções de leitura de arquivo.
 */
#ifndef _LERARQUIVO_H_
#define _LERARQUIVO_H_

#include "grafo.h"
#include <string>

using namespace std;

/**
 * @brief      Extrai as informações de vértices e arestas de um arquivo
 * e os adiciona num grafo representando números inteiros.
 *
 * @param      grafo         O grafo especificado.
 * @param[in]  nome_arquivo  O caminho do arquivo a ser lido.
 */
void lerArquivo(Grafo& grafo, string nome_arquivo);

#endif