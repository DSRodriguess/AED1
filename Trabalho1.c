#include <stdio.h>
#include <stdlib.h>
#define tam 10

void preencher(int vet[tam]){
	int i;
	printf("Preencha os numeros do vetor de 10 posicoes: \n");	
	for(i=0;i<tam;i++){
	scanf("%d",&vet[i]);
	}	
	for(i=0;i<tam;i++){
    	printf("%d vetor preenchido: \n",vet[i]);
    }
}

int buscaBinaria(int vet[tam], int valor){
    int comeco = 0, fim = tam-1;
    while(comeco <= fim){
        int index = (comeco+fim)/2; 
        if(vet[index] == valor){
            printf("Item encontrado na posicao: %d", index+1);
            return 0;
        }else if(vet[index] > valor){
            fim = index-1;
        }else{
            comeco = index+1;
        }
    }
    printf("Valor nao encontrado!");
    return -1;
}

int buscaLinear(int vet[tam], int valor){
	int i;
    for(i=0; i<tam; i++){
        if(vet[i] == valor){
            printf("Valor encontrado na posicao %d!", i+1);
            return 0;
        }        
    }
    printf("Valor nao encontrado!");
    return -1;
}

void insertionSort(int vet[tam],int n) {  
 	int i, j, temp;  
    for (i = 1; i < n; i++) {  
        temp = vet[i];  
        j = i - 1;  
  
        while(j>=0 && temp <= vet[j])  
        {    
            vet[j+1] = vet[j];     
            j = j-1;    
        }    
        vet[j+1] = temp;    
    }  
}

void selectionSort(int vet[tam], int n) {
   int i,j;
   for(i = 0; i < n - 1; i++) {
      int menor = i;
      for(j = i + 1; j < n; j++) {
         if (vet[j] < vet[menor]) menor = j;
      }
      int aux = vet[i];
      vet[i] = vet[menor];
      vet[menor] = aux;
   }
}
  
void sair(){
    printf("Saindo do programa\n");
    exit (0);
}

int main(){
	int vet[tam],aux,i,j,valor;
	int n = sizeof(vet) / sizeof(vet[0]), continuar=1, continuar2= 1;

    do
    {
        printf("\n\tDigite uma opcao\n\n");
        printf("1. Preencher o vetor\n");
        printf("2. Buscar por um valor:\n");
        printf("3. Ordenar o vetor\n");
        printf("4. Sair\n");

        scanf("%d", &continuar);
        system("cls || clear");

        switch(continuar)
        {
            case 1:
            	preencher(vet);
            	break;
            	
            case 2:	
            	printf("\n\tDigite uma opcao\n\n");
            	printf("1. Busca Binaria\n");
        		printf("2. Busca Sequencial\n");
        		
        		scanf("%d", &continuar2);
        		system("cls || clear");
        		
                if(continuar2 == 1){
                    printf("Qual valor deseja buscar no vetor ORDENADO? ");
   					scanf("%d", &valor);
   					buscaBinaria (vet,valor);
                }else if(continuar2 == 2){
	                printf("Digite o valor que voce deseja buscar: ");
    				scanf("%d", &valor);
    				buscaLinear(vet, valor);
                }
                break;
            case 3:
            	printf("\n\tDigite uma opcao\n\n");
            	printf("1. Ordenacao InsertionSort \n");
        		printf("2. Ordenacao SelectionSort \n");
        		
        		scanf("%d", &continuar2);
        		system("cls || clear");
        		
                if(continuar2 == 1){
                    insertionSort(vet,n);
                    for(i=0;i<tam;i++){
    	    			printf("%d",vet[i]);
    				}
                }else if(continuar2 == 2){
        			selectionSort(vet,n);
        			for(i=0;i<tam;i++){
    					printf("%d",vet[i]);
    				}
                }
        		break;
            case 4:
                sair();
                break;

            default:
                printf("Digite uma opcao valida\n");
        }
    } while(continuar);
}