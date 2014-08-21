#include <stdio.h>
#include <stdlib.h>

void print_sequence(int *,int);
void read_sequence(int *,int);

int main (){
	
	int *vec;
	int num;
	int x;
	int i;

	printf("Quanto numeros gostaria de inserir?\n");
	scanf("%d",&num);
	printf("Quantidade de numeros inseridos : %d\n", num);
	vec = malloc(num*sizeof(int));
	
	read_sequence(vec,num);
	print_sequence(vec,num);
	free (vec);
	return 0;
}

void read_sequence(int *vec,int num){
	int i;
	int x;
	printf("Estou aqui dentro!\n");
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
