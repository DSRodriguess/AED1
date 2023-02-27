/*
Considere uma lista encadeada de valores inteiros e implemente uma função para
retornar o número de nós da lista que possuem o campo info com valores maiores do que n
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

int NumeroNosN(int n){
    int cont = 0;
    no * aux ;
    while (aux != NULL){
        if(aux -> chave > n){
            cont ++;
        }
        aux = aux -> prox;
    }
    return cont;
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
    int x;
    inicializarLista();
    inserirInicio(5);
    inserirInicio(10);
    inserirInicio(3);
    x = NumeroNosN(4); //exemplo de numero n para busca; 
    printf("%d", x);

}