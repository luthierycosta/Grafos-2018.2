/**
 * Arquivo-cabeçalho contendo a declaração de funções adicionais de impressão na tela.
 */
#ifndef _IMPRIME_H
#define _IMPRIME_H

#include "grafo.h"

/**
 * @brief      Mostra na tela os graus do grafo e de cada um de seus vértices.
 *
 * @param      grafo 	O grafo de inteiros especificado.
 */
void imprimeGraus(Grafo& grafo);

/**
 * @brief      Mostra na tela os coeficientes de aglomeração do grafo e de cada um de seus vértices.
 *
 * @param      grafo  	O grafo de inteiros especificado.
 */
void imprimeCoefAglomeracao(Grafo& grafo);

/**
 * @brief      Mostra na tela os cliques maximais encontrados no grafo.
 *
 * @param      grafo  	O grafo de inteiros especificado.
 */
void imprimeCliques(Grafo& grafo);

#endif