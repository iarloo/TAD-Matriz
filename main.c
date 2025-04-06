#include <stdio.h>
#include <stdlib.h>
#include "Matriz.h"

int main() {
    Matriz *mat = NULL;
    int opcao;
    int linhas, colunas;
    int i, j;
    float valor;

    do {
        printf("\n=== MENU MATRIZ ===\n");
        printf("1. Criar matriz\n");
        printf("2. Atribuir valor\n");
        printf("3. Acessar valor\n");
        printf("4. Mostrar matriz\n");
        printf("5. Mostrar dimensões\n");
        printf("6. Liberar matriz\n");
        printf("0. Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                if (mat != NULL) {
                    matriz_libera(mat);
                }
                printf("Digite o número de linhas e colunas: ");
                scanf("%d %d", &linhas, &colunas);
                mat = matriz_cria(linhas, colunas);
                if (mat != NULL) {
                    printf("Matriz criada :\n");
                    matriz_imprime(mat);
                }else {
                    printf("Erro ao criar matriz\n");
                }
                break;

            case 2:
                if (mat == NULL) {
                    printf("crie uma matriz primeiro\n");
                    break;
                }
                printf("Digite a posição (linha coluna) e o valor:\n");
                printf("Digite a linha:");  scanf("%d", &i);
                printf("Digite a coluna:");  scanf("%d", &j);
                printf("Digite o valor:");  scanf("%d" ,&valor);

                if (matriz_atribui(mat, i, j, valor))
                    printf("Valor %f atribuído com sucesso!\n",valor);
                break;

            case 3:
                if (mat == NULL) {
                    printf("Crie a matriz primeiro!\n");
                    break;
                }
                printf("Digite a posição (linha coluna):\n");
                printf("Digite a linha:");  scanf("%d", &i);
                printf("Digite a coluna:");  scanf("%d", &j);

                printf("Valor: %.2f\n", matriz_acessa(mat, &i, &j));
                break;

            case 4:
                if (mat != NULL)
                    matriz_imprime(mat);
                else
                    printf("Crie a matriz primeiro\n");
                break;

            case 5:
                if (mat != NULL)
                    printf("Linhas: %d | Colunas: %d\n", matriz_linhas(mat), matriz_colunas(mat));
                else
                    printf("Crie primeiro uma matriz\n");
                break;

            case 6:
                matriz_libera(mat);
                mat = NULL;
                printf("Matriz liberada.\n");
                break;

            case 0:
                break;

            default:
                printf("Opção inválida\n");
        }

    } while(opcao != 0);

    if (mat != NULL)
        matriz_libera(mat);

    return 0;
}