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

int ultimoNo(){
    no * aux ;
    while (aux != NULL){
        if(aux -> prox == NULL){
            return aux -> chave;
        }
        aux = aux -> prox;
    }
}

int ultimoNo2(){
    int ultimo;
    no * aux ;
    while (aux != NULL){
        ultimo = aux -> chave;
        aux = aux -> prox;
    }
    return ultimo;
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
    inserirInicio(5);
    inserirInicio(10);
    inserirInicio(3);
    y = ultimoNo(); 
    printf("%d \n", y);
    x = ultimoNo2(); 
    printf("%d", x);

}]