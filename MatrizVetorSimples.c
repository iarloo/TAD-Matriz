#include "Matriz.h"
#include <stdio.h>
#include <stdlib.h>
struct matriz {
    int linhas, colunas;
    float *v; //vetor simples que guarda os valores
};

//cria: operação que cria uma matriz de dimensão m por n.

Matriz* matriz_cria(int linhas, int colunas) {

    Matriz* m = (Matriz*)malloc(sizeof(Matriz)); //Cria uma matriz m;
    if (m == NULL) return NULL;

    m->linhas = linhas;
    m->colunas = colunas;
    m->v = (float*)malloc(linhas * colunas * sizeof(float));
    if (m->v == NULL) {
        free(m);
        return NULL;
    }

    return m;

}

//libera: operação que libera a memória alocada para a matriz.

void matriz_libera( Matriz* m) {
    if (m != NULL) {
        free(m->v);
        free(m);
    }
}

//acessa: operação que acessa o elemento da linha i e da coluna j da matriz.

float matriz_acessa(Matriz* m, int *linha, int *coluna) {
    int indiceLinha = *linha , indiceColuna = *coluna;

    if (indiceLinha < 0 || indiceLinha >= m->linhas || indiceColuna < 0 || indiceColuna >= m->colunas) {
        printf("Indices fora do intervalo !");
        return 0;
    }

    return m->v[(indiceLinha * m->colunas) + indiceColuna];

}

int indice_invalido(Matriz *m, int indiceLinha, int indiceColuna) {
    return (indiceLinha < 0 || indiceLinha >= m->linhas || indiceColuna < 0 || indiceColuna >= m->colunas);
}

//•atribui : operação que atribui o elemento da linha i e da coluna j da matriz.

int matriz_atribui(Matriz* m, int indiceLinha, int indiceColuna, float v) {

    if (indice_invalido(m, indiceLinha, indiceColuna)) {
        printf("Índice inválido\n");
        return 0;
    }

    m->v[indiceLinha * m->colunas + indiceColuna] = v;
    return 1;
}

//linhas: operação que retorna o número de linhas da matriz.

int matriz_linhas(Matriz* m) {
    if (m == NULL) {
        printf("Matriz não existe");
        return 0;
    }
    return m->linhas;
}

//colunas: operação que retorna o número de colunas da matriz.

int matriz_colunas(Matriz* m) {
    if (m == NULL) {
        printf("Matriz não existe");
        return 0;
    }
    return m->colunas;
}

void matriz_imprime(Matriz* m) {
    if (m == NULL) {
        printf("Matriz inválida.\n");
        return;
    }

    for (int i = 0; i < m->linhas; i++) {
        for (int j = 0; j < m->colunas; j++) {
            printf("%.2f ", m->v[i * m->colunas + j]);
        }
        printf("\n");
    }
}