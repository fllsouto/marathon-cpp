#include <stdio.h>
#include <stdlib.h>


/*
Esse exemplo mostra que variaveis declaradas como constantes não podem ser alteradas,
entretanto um ponteiro constante pode ser alterado.

Ponteiros sempre tem comportamento de ponteiros, independente do quantificador (const) que você coloca nele.
*/
main(){
	int i = 12;
	const int ci = 100;
	const int ci2 = 101;
	// ci = 100;

	// Declearing a pointer to a integer constant
	const int *cpi;

	// Declearing a pointer to a integer
	int *ncpi;

	cpi = &ci;
	ncpi = &i;
	// *cpi = 10;
	printf("Before\n");
	printf("Const1 : %d\n", ci);
	printf("Const2 : %d\n", ci2);
	printf("Const Pointer : %d\n", *cpi);
	// printf("Other : %d\n", i);
	// printf("Other P: %d\n", *ncpi);

	// cpi = ncpi;
	cpi = &ci2;
	// ncpi = (int *)cpi;
	// *ncpi	= 0;


	printf("\nAfter\n");
	printf("Const : %d\n", ci);
	printf("Const2 : %d\n", ci2);
	printf("Const P : %d\n", *cpi);
	// printf("Other : %d\n", i);
	// printf("Other P: %d\n", *ncpi);

	exit(EXIT_SUCCESS);
}