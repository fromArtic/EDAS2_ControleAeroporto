#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "ControleAeroporto_Porcentagem.h"

int menu();

int main(){
    No *fila = NULL;
    No *r = NULL;
    int escolha, c;

    do{
        escolha = menu();
        if((escolha < 0) || (escolha > 3)){
            printf("\nESCOLHA INVALIDA.\n");
            system("PAUSE");
        }
        switch(escolha){
            case 1: //Registrar aviao
                printf("\n\nInforme a porcentagem de combustivel ainda disponivel no aviao: ");
                scanf("%d", &c);
                inserirComPrioridade(&fila, c);
                break;
            case 2: //Exibir fila
                imprimir(fila);
                break;
            case 3: //Avancar fila
                r = avancar(&fila);
                if(r){
                    printf("\n\n- O aviao em primeira colocacao foi removido da fila. -\n\n");
                    system("PAUSE");
                    free(r);
                }
                break;
            case 0: //Encerrar
                printf("\nEncerrando o programa . . .\n");
        }
    }while(escolha != 0);

    system("PAUSE");
    return 0;
}

int menu(){
    int escolha;

    system("CLS");

    printf("\n\tCONTROLE DE POUSO");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); //Vermelho
    printf("\t\t0 - Encerrar");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); //Branco
    printf("\n\n\t1 - Registrar aviao");
    printf("\n\t2 - Exibir fila");
    printf("\n\t3 - Avancar fila");
    printf("\n\n\tInsira sua escolha: ");
    scanf("%d", &escolha);

    return escolha;
}
