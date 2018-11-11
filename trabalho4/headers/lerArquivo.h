#ifndef _READFILE_
#define _READFILE_

#include "grafo.h"
#include <string>

using namespace std;

/**
 * @brief      Extrai as informações de vértices e arestas de um arquivo
 * e os adiciona num grafo de escolas e professores.
 *
 * @param      grafo         O grafo especificado.
 * @param[in]  nome_arquivo  O caminho do arquivo a ser lido.
 */
void lerArquivo(Grafo& grafo, string nome_arquivo);

#endif

