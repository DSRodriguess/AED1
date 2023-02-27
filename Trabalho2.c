#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int info;
    struct no *prox;
}no;

no *inicioL;

void inicializarLista(){
    inicioL = NULL;
}

int listaVazia(){
    if (inicioL == NULL){
        return 1;
    }else{
        return 0;
    }
}

void inserirInicio(int valor){
    no *aux;
    aux = (no*) malloc(sizeof(no));
    if (aux !=NULL){
        aux ->info =valor;
        aux -> prox = NULL;
        aux -> prox = inicioL;
        inicioL = aux;
    }
    else{
        printf("Não foi possivel inserir!");
    }
}

void percorrer(){
    no *aux;
    if (!listaVazia()){
        aux = inicioL;
        while(aux != NULL){
            printf ("%d \n",aux -> info);
            aux = aux -> prox;
        }
    }
    else{
        printf("\n Lista Vazia!");
    }
}

void inserirFim(int valor){
    no *aux, *p;
    aux =(no*) malloc(sizeof(no));
    if(aux != NULL){
        aux -> info = valor;
        aux -> prox = NULL;
        if (!listaVazia()){
            p = inicioL;
            while(p->prox != NULL){
                p = p -> prox;
            }
            p -> prox = aux;
        }
        else{
            inicioL = aux;
        }
    }
}

void remover(int valor){
    no *aux, *ant;
    aux = inicioL;
    ant = NULL;
    if (!listaVazia()){
        while (aux != NULL && aux -> info != valor){
            ant = aux;
            aux = aux -> prox;
        }
        if (aux == NULL){
            printf ("Valor não encontrado na lista");
        }
        else{
            if(ant == NULL){
                inicioL = aux->prox;
            }
            else{
                ant ->prox = aux ->prox;
            }
            free(aux);
        }               
    }
    else{
        printf("Lista vazia!");
    }
}

no* busca(int valor){
    no *aux;
    aux = inicioL;
    if (!listaVazia()){
        while (aux != NULL && aux -> info != valor){
            aux = aux -> prox;
        }
        return aux;            
    }
}

int main()
{
    int valor, op;
    inicializarLista();
    do{
        printf ("\n 1 - Insirir um elemento no inicio \n 2 - Insirir um elemento no final \n 3 - Pecorrer \n 4 - Remover um elemento \n 5 - Sair");
        printf ("\nInforme sua alternativa: ");
        scanf("%d",&op);
        if (op != 1 && op != 2 && op != 3 && op != 4 && op != 5){
            printf("Operação invalida");
        }
        else{
            if(op ==1){
                printf("\nvalor: ");
                scanf("%d", &valor);
                inserirInicio(valor);
            }
            else if(op ==2){
                printf("\nvalor: ");
                scanf("%d", &valor);
                inserirFim(valor);
            }
            else if(op == 3){
                percorrer();
            }
            else if(op == 4){
                printf("\nQual valor deseja remover: ");
                scanf("%d", &valor);
                remover(valor);
            }
            else{
                    printf("\n encerrando...");
            }
        }
        
    }while(op!=5);
    return 0;
}