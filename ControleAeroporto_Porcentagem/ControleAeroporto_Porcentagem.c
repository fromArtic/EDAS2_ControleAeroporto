#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "ControleAeroporto_Porcentagem.h"

void inserirComPrioridade(No **fila, int c){
    No *aux, *novo = malloc(sizeof(No)); //Alocacao de memoria das variaveis

    if(novo){
        novo->combRestante = c;
        novo->prox = NULL;
        if(*fila == NULL){ //Caso a fila esteja vazia, o no ocupara a primeira posicao
            *fila = novo;
        }else{ //Caso contrario, checa a prioridade do no (PRIORIDADE: combustivel disponivel < 25%)
            if(c < 25){ //Caso passe pelo if, eh prioridade
                if((*fila)->combRestante > 24){ //Checa se eh a primeira prioridade
                    novo->prox = *fila; //Se for, o no aponta para o inicio da fila
                    *fila = novo; //Insere o no no inicio da fila
                }else{ //Se nao for, busca sua posicao respectiva
                    aux = *fila;
                    while(aux->prox && aux->prox->combRestante < 25){ //Procura, enquanto houver um proximo elemento, por nos prioritarios
                        aux = aux->prox;
                    }
                    novo->prox= aux->prox; //Insere o no no apos a ultima prioridade
                    aux->prox = novo; //Aponta aux para a nova ultima prioridade
                }
            }else{ //Caso nao passe pelo if, nao eh prioridade
                aux = *fila;
                while(aux->prox){
                    aux = aux->prox;
                }
                aux->prox = novo;
            }
        }
        printf("\n- Aviao registrado a fila com sucesso. -\n\n");
        system("PAUSE");
    }else{
        printf("\nErro ao alocar memoria.\n");
        system("PAUSE");
    }
}

void imprimir(No *fila){
    printf("\n\n\t-------------------- FILA --------------------\n\t");
    while(fila){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1); //Azul
        printf("%d ", fila->combRestante);
        fila = fila->prox;
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); //Branco
    printf("\n\t--------------------      --------------------\n\t");
    printf("Prioridade para avioes com menos de 25 porcento\n\tde combustivel em estoque.\n\n\n");
    system("PAUSE");
}

No *avancar(No **fila){
    No *remover = NULL;

    if(*fila){
        remover = *fila;
        *fila = remover->prox;
    }else{
        printf("\nNao ha avioes na fila.\n");
        system("PAUSE");
    }

    return remover;
}
