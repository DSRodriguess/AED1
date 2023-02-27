/*
6. Implemente uma função que dados um valor e uma posição, a função insere o elemento
valor na posição pos da lista simplesmente encadeada. Para isso, um novo nó deve ser
alocado e ligado aos demais. O valor de pos é um número, que ser for 2, por exemplo, indica
que o novo nó alocado será o segundo nó da lista.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int chave;
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

void percorrer(){
    no *aux;
    if (!listaVazia()){
        aux = inicioL;
        while(aux != NULL){
            printf ("%d \n",aux -> chave);
            aux = aux -> prox;
        }
    }
    else{
        printf("\n Lista Vazia!");
    }
}

void inserirInicio(int valor){
    no *aux;
    aux = (no*) malloc(sizeof(no));
    if (aux !=NULL){
        aux ->chave =valor;
        aux -> prox = NULL;
        aux -> prox = inicioL;
        inicioL = aux;
    }
    else{
        printf("Não foi possivel inserir!");
    }
}



void inserirPos(int pos, int valor){
    no *aux, *ant, *temp = inicioL;
    aux = (no*) malloc (sizeof(no));
    if(aux != NULL){
        aux -> chave = valor;
    }
    else{
        printf("Não foi possivel inserir!");
    }
    int i = 0;
    if (pos == 0){
        aux -> prox = inicioL;
        inicioL = aux;
        return;
    }
    while(i!=pos){
        ant = temp;
        temp = temp -> prox;
        i++;
    }
    if(i == pos){
        ant -> prox = aux;
        aux -> prox = temp;
    }
    return;
}


int main()
{
    int x,y;
    inicializarLista();
    inserirInicio(10);
    inserirInicio(3);
    inserirInicio(10);
    inserirInicio(11);
    percorrer();
    
    //remover(10);
    printf("Lista nova \n");
    
    inserirPos(4, 5);
    percorrer();

}
