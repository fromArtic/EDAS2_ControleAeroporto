#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "ControleAeroporto_Ordenado.h"

int menu();

int main(){
    Fila *fila = criarFila();
    struct elemento aviaoRegistro, aviaoConsulta;
    int escolha, consulta, remove;

    do{
        escolha = menu();
        if((escolha < 0) || (escolha > 4)){
            printf("\nESCOLHA INVALIDA.\n");
            system("PAUSE");
        }
        switch(escolha){
            case 1: //Registrar aviao
                printf("\n\nInforme o ID do aviao que deseja registrar: "); //ID
                scanf("%d", &aviaoRegistro.id);
                printf("Agora, informe o modelo do aviao: "); //Modelo
                scanf("%s", &aviaoRegistro.modelo);
                printf("Insira a quantia de combustivel, em quilolitro, ainda disponivel: "); //Combustivel
                scanf("%f", &aviaoRegistro.combustivel);
                inserirComPrioridade(fila, aviaoRegistro); //Registro
                break;
            case 2: //Exibir fila
                imprimir(fila);
                break;
            case 3: //Consultar proximo aviao a pousar
                consulta = consultar(fila, &aviaoConsulta);
                if(consulta == 0){
                    printf("\nNao ha avioes na fila.\n");
                    system("PAUSE");
                }else if(consulta == 1){
                    printf("\n\n\t- FICHA DO PROXIMO AVIAO A POUSAR -\n");
                    printf("\t%s (ID: %d)\n\tCombustivel disponivel: %.2f kl\n\n\n", aviaoConsulta.modelo, aviaoConsulta.id, aviaoConsulta.combustivel);
                    system("PAUSE");
                }
                break;
            case 4: //Avancar fila
                remove = avancar(fila);
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
    printf("\n\t3 - Consultar proximo aviao a pousar");
    printf("\n\t4 - Avancar fila");
    printf("\n\n\tInsira sua escolha: ");
    scanf("%d", &escolha);

    return escolha;
}
