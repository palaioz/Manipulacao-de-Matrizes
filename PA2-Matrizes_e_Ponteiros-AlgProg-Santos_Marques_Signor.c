#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int menu1(){

    int opcao;
    do {

        printf("1 - Digitar o valor dos elementos da matriz\n");
        printf("2 - Gerar os elementos da matriz\n");
        printf("Digite a opção desejada: ");
        scanf("%d", &opcao);
        
        if (opcao != 1 && opcao != 2) 
        {
            printf("\nOpção inválida! Tente novamente.\n");
        }
    } while (opcao != 1 && opcao != 2);

    return opcao;
}


void ler_matriz(int *matriz, int N){

    int i, j;
    printf("Digite os elementos da matriz.");

    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
        {

            printf("Elemento[%d][%d]: ", i + 1, j + 1);
            scanf("%d", (matriz + i * N + j));
        }
    }
}

void gerar_matriz(int *matriz, int N){


    //GERAR OS VALORES DA MATRIZ RANDOMICAMENTE



}

int main(){
    setlocale(LC_ALL, "portuguese");
    
    int N;
    int *matriz;

    printf("Digite o valor de N que representa o número de linhas e colunas da matriz: ");
    scanf("%d", &N);

    matriz = (int *) malloc(N * N * sizeof(int));
    
    if (matriz == NULL){
        printf("Erro ao alocar memória.\n");
        exit(-1);
    }

    switch (menu1()){

        case 1:
            ler_matriz(matriz, N);
            break;

        case 2:
            gerar_matriz(matriz, N);
            break;
    }

   //MENU2 com 3 opçoes
   //A - Classe da matriz -> verificar se é simétrica, diagonal, triangular superior ou triangular inferior
   //B - Cálculos sobre a matriz -> ler um valor X e criar uma nova matriz que seja o resultado da matriz original multiplicado pelo valor X, printar nova matriz
   //C - Sair(encerrar programa, return 0;)


    free(matriz);
    
    return 0;
}
