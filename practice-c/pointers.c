#include <stdio.h>
#include <stdlib.h>

void test_a(int *x, int *y){
  printf("A - Endereço de X na funcao: %p\n", (void*)x);
  printf("A - Endereço de y na funcao: %p\n", (void*)y);
  printf("\n");
  
}

void test_b(int x, int *y){
  int *k = y;
  printf("B - Endereço de X na funcao: %p\n", (void*)&x);
  printf("B - Endereço de y na funcao: %p\n", (void*)y);
  *k = 315;
  printf("\n");
}

// int main(){
//   int x = 10;
//   int* y;
//   y = &x;
//   printf("Endereço de X : %p\n", (void*)&x);
//   printf("Endereço de Y : %p\n", (void*)&y);
//   printf("Endereço de X por Y : %p\n", (void*)y);
//   printf("------------------------------\n");
//   printf("Conteudo de X : %d\n", x);
//   printf("Conteudo de *Y : %d\n", *y);
//   printf("------------------------------\n");
//   test_a(&x,y);
//   test_b(x,y);
//   printf("Conteudo de X : %d\n", x);
//   return 0;
// }

void show_vector(int *y,int n){
  int i = 0;
  for(i; i < n; i++){
    printf("[%d] :: %d\n",i, y[i]);
  }
}

int main(){
  int* y;
  int x = 10;
  int i = 0;
  y = malloc(x*sizeof(int));
  for(i = 0;i < x;i++){ y[i] = i*i;}
  show_vector(y, x);
  return 0;
}