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
        printf("0 - Sair\n");
        printf("Digite a opção desejada: ");
        scanf("%d", &opcao);
        
        if (opcao != 1 && opcao != 2 && opcao != 0) {
            printf("\nOpção inválida! Tente novamente.\n");
        }
    } while (opcao != 1 && opcao != 2 && opcao != 0);
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

    // Valida ponteiro nulo ou tamanho inválido 
    if (matriz == NULL || N <= 0) {
        printf("\n[ERRO] Falha ao gerar matriz: ponteiro inválido ou dimensão menor/igual a zero.\n");
        return;
    }

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
    // Valida ponteiro nulo ou tamanho inválido antes de exibir.
    if (matriz == NULL || N <= 0) {
        printf("\n[ERRO] Falha ao exibir matriz: matriz não alocada ou inválida.\n");
        return;
    }
    
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
    while (scanf("%d", &N) != 1 || N <= 0) {
        printf("[ERRO] Valor inválido! Digite um número inteiro maior que zero.\n");
            while(getchar() != '\n'); // Limpa o buffer
    }

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
        case 0:
            printf("Saindo do programa");
            exit(0);
    }

    exibir_matriz(matriz, N);

    /*
     *  A FAZER:
     *  ----------- 
     *  1. Imnplementar o MENU 2:
     *      - Opção A (Classe da Matriz):
     *          * Verificar se é Simétrica (A[i][j] == A[j][i])
     *          * Verificar se é Diagonal (A[i][j] == 0 para i != j)
     *          * Verificar se é Triangular Superior (A[i][j] == 0 para i > j)
     *          * Verificar se é Triangular Inferior (A[i][k] == 0 para i < j)
     *      - Opção B (Cálculos sobre a Matriz):
     *          * Multiplicação por um valor escalar X (gerar e exibir nova matriz)
     *          * Calcular e mostrar a soma dos elementos da diagonal principal 
     *          * Calcular e armazenar em um vetor a soma dos elementos de cada linha 
     * */

    // Liberação da memória alocada 
    free(matriz);
    
    return 0;
}
