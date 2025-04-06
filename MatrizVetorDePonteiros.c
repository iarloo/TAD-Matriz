#include "Matriz.h"
#include <stdlib.h>
#include <stdio.h>

struct matriz {
    int linhas, colunas;
    float **v;
};

//•cria : operação que cria uma matriz de dimensão m por n.

Matriz* matriz_cria(int linhas, int colunas) {
    //Aloca um vetor para cada elemento da linha.
    Matriz *m = (Matriz*)malloc(sizeof(Matriz));
    if (m == NULL) {
        return NULL;
    }

    //Faz uma cópia dos valores do usuario para a estrutura criada.
    m->linhas = linhas;
    m->colunas = colunas;

    // Aloca vetor de ponteiros para cada linha
    m->v = (float**)malloc(linhas * sizeof(float*));
    if (m->v == NULL) {
        free(m);
        return NULL;
    }

    for (int i = 0; i < linhas; i++) {
        m->v[i] = (float*)malloc(colunas * sizeof(float));
        if (m->v[i] == NULL) {
            // Libera tudo em caso de erro
            for (int j = 0; j < i; j++) free(m->v[j]);
            free(m->v);
            free(m);
            return NULL;
        }
    }
    return m;

}

//•libera : operação que libera a memória alocada para a matriz.

void matriz_libera( Matriz* m) {
    if (m != NULL) {
        for (int i =0; i < m->linhas; i++) {
            free(m->v[i]);
        }
        free(m->v);
        free(m);
    }
}

//•acessa : operação que acessa o elemento da linha i e da coluna j da matriz.

float matriz_acessa(Matriz* m, int *linha, int *coluna) {
    if (m == NULL || linha == NULL || coluna == NULL) {
        printf("Erro: ponteiro nulo.\n");
        return 0;
    }

    int i = *linha;
    int j = *coluna;

    if (indice_invalido(m,i,j)) {
        printf("Erro: índices fora do intervalo.\n");
        return 0;
    }

    return m->v[i][j];
}

//•atribui : operação que atribui o elemento da linha i e da coluna j da matriz.

int matriz_atribui(Matriz* m, int indiceLinha, int indiceColuna, float v) {
    if (indice_invalido(m, indiceLinha, indiceColuna)) {
        printf("Índice inválido\n");
        return 0;
    }

    m->v[indiceLinha][indiceColuna] = v;
    return 1;
}

//•linhas : operação que retorna o número de linhas da matriz.

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

int indice_invalido(Matriz* m, int indiceLinha, int indiceColuna) {
    return (indiceLinha < 0 || indiceLinha >= m->linhas || indiceColuna < 0 || indiceColuna >= m->colunas);
}

//Debug ?
void matriz_imprime(Matriz* m) {
    if (m == NULL) {
        printf("Matriz inválida.\n");
        return;
    }

    for (int i = 0; i < m->linhas; i++) {
        for (int j = 0; j < m->colunas; j++) {
            printf("%.2f ", m->v[i][j]);
        }
        printf("\n");
    }
}

