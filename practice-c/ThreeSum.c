#include <stdio.h>
#include <stdlib.h>

void print_sequence(int *,int);
void read_sequence(int *,int);
int three_sum_brutal_force(int *,int);
void show_triple(int, int, int);

int main (){
	
	int *vec;
	int num;
	int x;
	int i;
	int finalQnt = 0;

	printf("Quanto numeros gostaria de inserir?\n");
	scanf("%d",&num);
	printf("Quantidade de numeros inseridos : %d\n", num);
	vec = malloc(num*sizeof(int));
	
	read_sequence(vec,num);
	finalQnt = three_sum_brutal_force(vec,num);
	printf("Quantidade encontrada : %d\n", finalQnt);
	free (vec);
	return 0;
}
int three_sum_brutal_force(int *vec,int num){
	int i;
	int j;
	int k;
	int qnt = 0;

	for (i = 0; i < num; i++){
		for (j = i+1; j < num; j++){
			for (k = j+1; k < num; k++){
				if (vec[i] + vec[j] + vec[k] == 0){
					qnt++;
					// show_triple(vec[i],vec[j],vec[k]);
				}
			}
		}
	}
	return qnt;
}

void show_triple(int i, int j, int k){
	printf("(%d,%d,%d)\n", i,j,k);
}

void read_sequence(int *vec,int num){
	int i;
	int x;
	for(i = 0; i < num; i++){
		printf("Insira o #%d : ", i);
		scanf("%d",&x);
		vec[i] = x;	
	}
}

void print_sequence(int *vec,int num){
	int i;
	printf("Estou aqui dentro!\n");
	for(i = 0; i < num; i++){
		printf("#%d : %d\n", i,vec[i]);
	}
}
