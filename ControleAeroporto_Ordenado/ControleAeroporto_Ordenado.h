//Registro dos avioes
struct elemento{
    int id;
    char modelo[50];
    float combustivel;
};

//Redefinicao de tipoFila para Fila
typedef struct tipoFila Fila;

//Registra avioes a lista (prioridade a avioes com menos combustivel)
void inserirComPrioridade(Fila* fila, struct elemento aviao);

//Exibe a fila ordenada de avioes
void imprimir(Fila* fila);

//Consulta o proximo aviao a pousar
int consultar(Fila* fila, struct elemento *aviao);

//Apos seu pouso, remove o aviao em primeira colocacao e avanca a fila
int avancar(Fila* fila);
