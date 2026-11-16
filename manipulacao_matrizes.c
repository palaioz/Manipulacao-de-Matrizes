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

#if defined(_WIN32) || defined(_WIN64)
    #include <windows.h>
#endif


// === DECLARAÇÃO DE FUNÇÕES === 

// --- Menus ---

// Autor: Vitor Zeferino Marques 
int menu1() {

    int opcao;
    int resultado;

    do {
        printf("\n--- OPERAÇÕES COM MATRIZES ---\n");
        printf("1 - Digitar o valor dos elementos da matriz\n");
        printf("2 - Gerar os elementos da matriz\n");
        printf("0 - Sair\n");
        printf("Digite a opção desejada: ");
        resultado = scanf("%d", &opcao);

        while (getchar() != '\n');

        if (resultado != 1) {
            printf("\n[ERRO] Entrada inválida! Digite apenas números inteiros (0, 1 ou 2).\n");
            opcao = -1;
        } else if (opcao != 1 && opcao != 2 && opcao != 0) {
            printf("\n[ERRO] Opção inválida! Tente novamente.\n");
        }

    } while (opcao != 1 && opcao != 2 && opcao != 0);
    
    return opcao;
}

// Autor: Antônio Gonçalves dos Santos 
char menu2() {
    char opcao;

    do {
        printf("\n--- MENU DE OPERAÇÕES ---\n");
        printf("A - Classe da matriz\n");
        printf("B - Cálculos sobre a matriz\n");
        printf("C - Sair do programa\n");
        printf("Digite a opção desejada: \n");

        scanf(" %c", &opcao);
        
        // Padroniza para maiúscula para aceitar tanto 'a' quanto 'A', etc.
        if (opcao >= 'a' && opcao <= 'z') {
            opcao = opcao - 32; // valores da tabela ASCII 
        }

        if (opcao != 'A' && opcao != 'B' && opcao != 'C') {
            printf("\n[ERRO] Opção inválida! Tente novamente.\n");
        }

    } while (opcao != 'A' && opcao != 'B' && opcao != 'C');

    return opcao;
}

// --- Leitura e Exibição Matriz ---

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

// --- Cálculos Matriz ---

// Autor: Antônio Gonçalves dos Santos
int soma_diagonal_matriz(int *matriz, int N) {
    int soma = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) {
                soma += *(matriz + i * N + j);
            }
        }
    }

    return soma;
}

// Autor: Vítor Zeferino Marques
int *soma_linhas_matriz(int *matriz, int N){

    int *soma = (int *) malloc(N * sizeof(int));
    if(soma == NULL){
        printf("Erro ao alocar memória.\n");
        exit(-1);
    }
    int i, j;

    for(i = 0; i < N; i++){
        soma[i] = 0;
        for(j = 0; j < N; j++){
            soma[i] += *(matriz + i * N + j);
        }

    }

    return soma;
}

// Autor: Antônio Gonçalves dos Santos 
int *multiplicar_matriz_escalar(int *matriz, int N, int escalar) {
    int *nova_matriz = (int *) malloc(N * N * sizeof(int));
    if (nova_matriz == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(-1);
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            *(nova_matriz + i * N + j) = *(matriz + i * N + j) * escalar;
        }
    }

    return nova_matriz;
}

// --- MAIN --- 

int main(){
    #if defined(_WIN32) || defined(_WIN64)
        SetConsoleOutputCP(65001);
    #else
        setlocale(LC_ALL, "pt_BR.UTF-8");
    #endif 
    
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
            printf("Saindo do programa...\n");
            free(matriz);
            exit(0);
    }

    exibir_matriz(matriz, N);

    // Loop do Menu 2
    char opcao_menu2;
    do {
        opcao_menu2 = menu2();

        switch (opcao_menu2) {
            case 'A':
                printf("\n[A FAZER] Opção A selecionada: Classe da matriz (Simétrica, Diagonal, Triangular Superior/Inferior).\n");
                break;
            
            case 'B':
                int escalar = 0;
                
                printf("\n--- CÁLCULOS DA MATRIZ ---");
                printf("\nDigite um inteiro como escalar: ");
               
                // Se o usuário digitar letra/síbolo, repete apenas esse input 
                while (scanf("%d", &escalar) != 1) {
                    printf("\n[ERRO] Entrada inválida! Digite apenas um número inteiro para o escalar: ");
                    while (getchar() != '\n'); // Limpa o buffer com o caractere inválido 
                } 
                while (getchar() != '\n'); // Limpa o buffer após o enter do número correto

                int soma_diagonal = soma_diagonal_matriz(matriz, N);
                int *soma_linhas = soma_linhas_matriz(matriz, N);

                int *matriz_multiplicada = multiplicar_matriz_escalar(matriz, N, escalar);
                printf("\nMatriz Multiplicada por %d: \n", escalar);
                exibir_matriz(matriz_multiplicada, N);

                free(matriz_multiplicada);

                printf("\nSoma da Diagonal da Matriz: %d\n", soma_diagonal);

                for(int c = 0; c < N; c++){
                    printf("\nSoma da linha %d: %d\n", c + 1, soma_linhas[c]);
                }

                free(soma_linhas);
                break;
                
            case 'C':
                printf("\nSaindo do programa...\n");
                break;
        }
    } while (opcao_menu2 != 'C');

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
     *          * Calcular e armazenar em um vetor a soma dos elementos de cada linha 
     * */

    // Liberação da memória alocada 
    free(matriz);

    
    return 0;
}
