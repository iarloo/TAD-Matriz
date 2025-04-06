#ifndef MATRIZ_H
#define MATRIZ_H

typedef struct matriz Matriz;

//•cria : operação que cria uma matriz de dimensão m por n.

Matriz* matriz_cria(int linhas, int colunas);

//•libera : operação que libera a memória alocada para a matriz.

void matriz_libera( Matriz* m);

//•acessa : operação que acessa o elemento da linha i e da coluna j da matriz.

float matriz_acessa(Matriz* m, int *linha, int *coluna);

//•atribui : operação que atribui o elemento da linha i e da coluna j da matriz.

int matriz_atribui(Matriz* m, int indiceLinha, int indiceColuna, float v);

//•linhas : operação que retorna o número de linhas da matriz.

int matriz_linhas(Matriz* m);

//•colunas : operação que retorna o número de colunas da matriz.

int matriz_colunas(Matriz* m);

int indice_invalido(Matriz* m, int indiceLinha, int indiceColuna);

//Debug ?
void matriz_imprime(Matriz* m);



#endif //MATRIZ_H
