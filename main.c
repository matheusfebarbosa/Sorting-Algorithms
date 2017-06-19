#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "tad.h"

int main(int argc, char *argv[]){
	
	//Dados de entrada
	char *algoritmo;
	int n_entradas;
	char *situacao;
	int flag_imprimir = 0;

	//Vetor que vai ser ordenado
	int *vetor; 

	//Variáveis para calcular o tempo de execução
	clock_t inicio,fim;
	float tempo;
	unsigned long long comp=0, mov=0;

	//Variáveis auxiliares
	char *aux;
	int count;


	if(argc>=4){
		algoritmo = argv[1];
		n_entradas = atoi(argv[2]);
		situacao = argv[3];
		if(argc>=5){
			aux = argv[4];
			if(!strcmp(aux,"-P")){
				flag_imprimir = 1;
			}else{
				fprintf(stderr,"Erro: Argumento 4 inválido\n");
				return 1;
			}
		}
	}else{
		fprintf(stderr,"Erro: Faltam argumentos para a execução\n");
		return 1;
	}

	vetor = (int*) malloc(n_entradas*sizeof(int));

	srand(time(NULL));

	if(flag_imprimir){
		printf("Vetor gerado: ");
	}

	if(!strcmp(situacao,"Rand")){
		for(count=0; count<n_entradas; count++){
			vetor[count] = 1 + rand() % n_entradas;
			if(flag_imprimir){
				printf("%d ", vetor[count]);
			}
		}
		printf("Tipo de Vetor: Aleatório\n");
	}else if(!strcmp(situacao,"Cres")){
		for(count=0; count<n_entradas; count++){
			vetor[count] = count+1;
			if(flag_imprimir){
				printf("%d ", vetor[count]);
			}
		}
		printf("Tipo de Vetor: Crescente\n");
	}else if(!strcmp(situacao,"Decr")){
		for(count=n_entradas; count>0; count--){
			vetor[count] = count;
			if(flag_imprimir){
				printf("%d ", vetor[count]);
			}
		}
		printf("Tipo de Vetor: Decrescente\n");
	}else if(!strcmp(situacao,"QOrd")){
		for(count=0; count<(round(n_entradas*0.9)); count++){
			vetor[count] = count+1;
			if(flag_imprimir){
				printf("%d ", vetor[count]);
			}
		}
		for(count; count<n_entradas; count++){
			vetor[count] = 1 + rand() % n_entradas;
			if(flag_imprimir){
				printf("%d ", vetor[count]);
			}
		}
		printf("Tipo de Vetor: Quase Ordenado\n");
	}else{
		fprintf(stderr,"Erro: Parametro situacao inválido\n");
		return 1;
	}

	if(flag_imprimir){
		printf("\n");
	}
	
	printf("Número de entradas: %d\n", n_entradas);
	
	if(!strcmp(algoritmo,"Ins")){
		printf("Algoritmo: InsertionSort\nExecutando o algorimo...\n");
		inicio = clock();
		insertionSort(vetor,n_entradas,&comp,&mov);
		fim = clock();

	}else if(!strcmp(algoritmo,"Sel")){
		printf("Algoritmo: SelectionSort\nExecutando o algorimo...\n");
		inicio = clock();
		selectionSort(vetor,n_entradas,&comp,&mov);
		fim = clock();
	}else if(!strcmp(algoritmo,"Bub")){
		printf("Algoritmo: BubbleSort\nExecutando o algorimo...\n");
		inicio = clock();
		bubbleSort(vetor,n_entradas,&comp,&mov);
		fim = clock();
	}else if(!strcmp(algoritmo,"She")){
		printf("Algoritmo: ShellSort\nExecutando o algorimo...\n");
		inicio = clock();
		shellSort(vetor,n_entradas,&comp,&mov);
		fim = clock();
	}else if(!strcmp(algoritmo,"Qui")){
		printf("Algoritmo: QuickSort\nExecutando o algorimo...\n");
		inicio = clock();
		quickSort(vetor,0,n_entradas-1,&comp,&mov);
		fim = clock();
	}else if(!strcmp(algoritmo,"Hea")){
		printf("Algoritmo: HeapSort\nExecutando o algorimo...\n");
		inicio = clock();
		heapSort(vetor,n_entradas,&comp,&mov);
		fim = clock();
	}


	printf("Fim de execução\n");
	tempo = (float) (fim-inicio)/CLOCKS_PER_SEC;

	printf("Tempo: %f segundos\nComparações: %llu\nMovimentações: %llu\n", tempo,comp,mov);

	if(flag_imprimir){
		printf("Vetor ordenado: ");
		for(count=0; count<n_entradas; count++){
			printf("%d ", vetor[count]);
		}
		printf("\n");
	}

	free(vetor);

	return 0;
}
