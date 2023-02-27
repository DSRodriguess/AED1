/*
Implemente uma função que retorne o valor armazenado no último nó de uma lista
encadeada de números inteiros. 
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

void remover(int valor){
    no *aux, *ant;
    aux = inicioL;
    ant = NULL;
    while (aux != NULL){
        if(aux -> chave == valor){
            if(ant != NULL){
                ant -> prox = aux->prox;
            }
            else{
                aux = aux ->prox;
                ant == NULL;
            }
        }
        ant = aux;
        aux = aux -> prox;
    }
    free(aux);
    return;
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


int main()
{
    int x,y;
    inicializarLista();
    inserirInicio(10);
    inserirInicio(3);
    inserirInicio(10);
    inserirInicio(11);
    percorrer();
    
    remover(10);
    printf("Lista nova \n");
    percorrer();

}