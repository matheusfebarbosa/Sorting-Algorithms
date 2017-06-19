void insertionSort(int vetor[], int tam, unsigned long long *comp, unsigned long long *mov){
	int countx, county;
	int atual, aux;
	*comp = 0;
	*mov = 0;

	for(countx=1; countx<tam; countx++){
		county = countx - 1;
		atual = vetor[countx];
		(*comp)++;
		while(vetor[county]>atual){
			vetor[county+1] = vetor[county];
			vetor[county] = atual;
			county--;
			(*mov)++;
			if(county<0){
				break;
			}
			(*comp)++;
		}
	}
}

void selectionSort(int vetor[], long int tam, unsigned long long *comp, unsigned long long *mov){
	int countx, county;
	int i_min,aux;
	*comp = 0;
	*mov = 0;

	for(countx=0; countx<tam-1; countx++){
		i_min = countx;
		for(county = countx+1; county<tam; county++){
			(*comp)++;
			if(vetor[i_min]>vetor[county]){
				i_min = county;
			}
		}
		aux = vetor[countx];
		vetor[countx] = vetor[i_min];
		vetor[i_min] =  aux;
		(*mov)++;
	}
}

void bubbleSort(int vetor[], int tam, unsigned long long *comp, unsigned long long *mov){
	int countx, county;
	int aux;
	*comp = 0;
	*mov = 0;

	for(countx=0; countx<tam; countx++){
		for(county = 0; county<tam-countx; county++){
			(*comp)++;
			if(vetor[county]>vetor[county+1]){		
				aux = vetor[county];
				vetor[county] = vetor[county+1];
				vetor[county+1] =  aux;
				(*mov)++;
			}
		}
	}
}

void shellSort(int vetor[], int tam, unsigned long long *comp, unsigned long long *mov){
	int countx, county=0;
	int atual, aux, h=1;
	*comp = 0;
	*mov = 0;

	while(h<tam){
		h = 3 * h + 1;
	}
	
	while(h>0){
		h = (h-1)/3;
		for(countx=h; countx<tam; countx++){
			aux = vetor[countx];
			county = countx;
			(*comp)++;
			while(vetor[county-h]>aux){
				vetor[county] = vetor[county-h];
				county -= h;
				(*mov)++;
				if (county<h){
					break;
				}
				(*comp)++;
			}
			vetor[county] = aux;
		}
	}
}

void quickSort(int vetor[], int esquerda, int direita, unsigned long long *comp, unsigned long long *mov){
	int pivo,aux,part=0;
	int esq=esquerda, dir=direita;

	if(esquerda<direita){
		pivo = (vetor[dir] + vetor[esq] + vetor[((dir+esq)/2)])/3;
		
		while(esq<=dir){
			(*comp)++;
			while(vetor[esq]<pivo){
				esq++;
				(*comp)++;
			}
			(*comp)++;
			while(vetor[dir]>pivo){
				dir--;
				(*comp)++;
			}
			if(esq<=dir){
				aux = vetor[esq];
				vetor[esq] = vetor[dir];
				vetor[dir] =  aux;	
				(*mov)++;
				esq++;
				dir--;
			}
		}

		quickSort(vetor,esquerda,dir,comp,mov);
		quickSort(vetor,esq,direita,comp,mov);
	}

}

void heapSort(int vetor[], int tam, unsigned long long *comp, unsigned long long *mov){
	int pai, filho;
	int aux;
	while(tam>1){
		for(pai=tam/2;pai>=0;pai--){
			filho = 2*pai+1;
			aux = vetor[pai];	
			while(filho<tam){
				(*comp)++;
				if(filho+1<tam && vetor[filho]<vetor[filho+1]){
					filho++;
				}
				(*comp)++;
				if(aux<vetor[filho]){
					vetor[pai] = vetor[filho];
					pai = filho;
					filho = 2*pai+1;
					(*mov)++;
				}else{
					break;
				}
			}
			vetor[pai]=aux;
		}
		aux = vetor[0];
		vetor[0] = vetor[tam-1];
		vetor[tam-1] = aux;
		(*mov)++;
		tam--;
	}
}