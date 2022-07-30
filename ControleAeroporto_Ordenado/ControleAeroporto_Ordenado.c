#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "ControleAeroporto_Ordenado.h"

//Registro dos nos
typedef struct tipoNo{
    struct elemento dado;
    struct tipoNo *prox;
}noFila;

//Registro das filas
struct tipoFila{
    struct tipoNo *inicio;
    struct tipoNo *fim;
    int qtd;
};

Fila* criarFila(){
    Fila* fila = (Fila*) malloc(sizeof(Fila)); //Alocacao de memoria

    if(fila != NULL){ //Checa se ainda nao foi alocado espaco para a fila
        fila->fim = NULL;
        fila->inicio = NULL;
        fila->qtd = 0;
    }

    return fila;
}

void inserirComPrioridade(Fila* fila, struct elemento aviao){
    if(fila == NULL){ //Nao foi alocado espaco para a fila
        printf("\nOcorreu um erro.\n");
        system("PAUSE");
    }else{
        noFila *novoNo = (noFila*) malloc(sizeof(noFila)); //Alocacao de memoria

        if(novoNo == NULL){
            printf("\nErro ao alocar memoria.\n");
            system("PAUSE");
        }else{
            novoNo->dado = aviao;

            if(fila->inicio == NULL){ //Caso a fila esteja vazia, o no ocupara a primeira posicao
                fila->inicio = novoNo;
                fila->fim = novoNo;
                novoNo->prox = NULL;
            }else{ //Caso contrario, checa a prioridade do no
                noFila *ant, *atual = fila->inicio;

                while(atual != NULL && atual->dado.combustivel < aviao.combustivel){
                    ant = atual;
                    atual = atual->prox;
                }
                if(atual == fila->inicio){
                    novoNo->prox = fila->inicio;
                    fila->inicio = novoNo;
                }else{
                    novoNo->prox = atual;
                    ant->prox = novoNo;
                }
            }
            fila->qtd++;
            printf("\n- Aviao registrado a fila com sucesso. -\n\n");
            system("PAUSE");
        }
    }
}

void imprimir(Fila* fila){
    if(fila == NULL){ //Nao foi alocado espaco para a fila
        printf("\nOcorreu um erro.\n");
        system("PAUSE");
        return;
    }

    noFila* no = fila->inicio;

    printf("\n\n\t---------------------------------------- FILA ----------------------------------------\n\t");
    while(no != NULL){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1); //Azul
        printf("%d ", no->dado.id);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); //Vermelho
        printf("%(%.3f kl) ", no->dado.combustivel);
        no = no->prox;
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); //Branco
    printf("\n\t----------------------------------------      ----------------------------------------\n\t");
    if(fila->qtd > 1){
        printf("No momento, ha %d avioes aguardando\n\tautorizacao para pousarem.\n\n\n", fila->qtd);
    }
    if(fila->qtd == 1){
        printf("No momento, ha somente um aviao\n\taguardando autorizacao para pousar.\n\n\n");
    }
    if(fila->qtd == 0){
        printf("No momento, a fila esta vazia.\n\n\n");
    }
    system("PAUSE");
}

int consultar(Fila* fila, struct elemento *aviao){
    if(fila == NULL){ //Nao foi alocado espaco para a fila
        printf("\nOcorreu um erro.\n");
        system("PAUSE");
        return 0;
    }
    if(fila->inicio == NULL){ //Fila vazia
        return 0;
    }

    *aviao = fila->inicio->dado;

    return 1;
}

int avancar(Fila* fila){
    if(fila != NULL){
        if(fila->inicio != NULL){
            noFila *aux = fila->inicio;
            fila->inicio = fila->inicio->prox;
            if(fila->inicio == NULL){
                fila->fim = NULL;
            }
            free(aux);
            fila->qtd--;
            printf("\n\n- O aviao em primeira colocacao foi removido da fila. -\n\n");
            system("PAUSE");
            return 1;
        }else{
            printf("\nNao ha avioes na fila.\n");
            system("PAUSE");
            return 0;
        }
    }else{
        printf("\nOcorreu um erro.\n");
        system("PAUSE");
        return 0;
    }
}
