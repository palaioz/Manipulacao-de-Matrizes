/*
 * ====================================================================================
 * UNIVERSIDADE FRANCISCANA (UFN)
 * Curso: Ciência da Computação 
 * Disciplina: Algoritmos e Programação B 
 * Produto de Aprendizagem 2 - Manipulação de matrizes 
 *
 * Integrantes do Grupo:
 *  - Antônio Gonçalves dos Santos
 *  - Bernardo Quaiatto Signor 
 *  - Vitor Zeferino Marques 
 * ====================================================================================
 *  
 *  Objetivos do Programa:
 *      1- Informar os elementos da Matriz (leitura manual)
 *      2 - Gerar os elementos da Matriz de forma randômica 
 *
 *  Menu de Operações (Menu 2)
 *      A - Classe da matriz (simétrica, diagonal, triangular superior/inferior)
 *      B - Cálculos sobre a matriz (multiplicação por escalar, diagonal principal
 *          soma das linhas)
 *      C - Sair do programa
 *  */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>


// --- DECLARAÇÃO DE FUNÇÕES --- 

// Autor: Vitor Zeferino Marques 
int menu1() {

    int opcao;
    do {

        printf("1 - Digitar o valor dos elementos da matriz\n");
        printf("2 - Gerar os elementos da matriz\n");
        printf("Digite a opção desejada: ");
        scanf("%d", &opcao);
        
        if (opcao != 1 && opcao != 2) {
            printf("\nOpção inválida! Tente novamente.\n");
        }
    } while (opcao != 1 && opcao != 2);

    return opcao;
}

// Autor: Vitor Zeferino Marques 
void ler_matriz(int *matriz, int N){

    int i, j;
    printf("Digite os elementos da matriz\n");

    for(i = 0; i < N; i++) {
        for(j = 0; j < N; j++) {

            printf("Elemento[%d][%d]: ", i + 1, j + 1);
            scanf("%d", (matriz + i * N + j));
        }
    }
}

// Autor: Antônio Gonçalves dos Santos
void gerar_matriz(int *matriz, int N) {
    srand(time(NULL)); // inicializa a 'seed' randômica baseada no tempo atual

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            // Atribui valores aleatórios de 1 a 99 para cada posição da matriz 
            *(matriz + i * N + j) = (rand()%99) + 1;
        }
    }
    printf("\n[INFO] Matriz gerada randomicamente com sucesso!\n");
}

// Autor: Antônio Gonçalves dos Santos 
void exibir_matriz(int *matriz, int N) {
    printf("\nMatriz Atual (%d x %d):\n", N, N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%4d", *(matriz + i * N + j));
        }
        printf("\n");
    }
}


// --- MAIN --- 

int main(){
    setlocale(LC_ALL, "portuguese");
    
    int N;
    int *matriz;

    printf("Digite o valor de N que representa o número de linhas e colunas da matriz: ");
    scanf("%d", &N);

    // Alocação dinâmica de memória para a matriz N x N 
    matriz = (int *) malloc(N * N * sizeof(int));
    
    if (matriz == NULL){
        printf("Erro ao alocar memória.\n");
        exit(-1);
    }

    // Seleção de entrada via Menu 1 
    switch (menu1()){
        case 1:
            ler_matriz(matriz, N);
            break;

        case 2:
            gerar_matriz(matriz, N);
            break;
    }

    exibir_matriz(matriz, N);

    /*
     *  A FAZER:
     *  - Implementar o MENU 2 (Classes da Matriz e cálculos)
     * */

    // Liberação da memória alocada 
    free(matriz);
    
    return 0;
}
