#include <stdio.h>
#include <math.h>
#include <stdlib.h>



// double randn(double mu, double sigma){
//   double U1, U2, W, mult;
//   static double X1, X2;
//   static int call = 0;
//
//   if(call == 1)
// }

void show_rand(int, int,float);

int main(){
  int foo;
  int seed = 0;
  float prob = 0;
  printf("Insira a qnt : ");
  scanf("%d",&foo);
  printf("Insira a probabilidade: ");
  scanf("%f",&prob);
  printf("Insira a seed: ");
  scanf("%d",&seed);
  // printf("\n\nValor inserido : %f",foo);
  // printf("\n\nValor seed inserido : %d",seed);

  show_rand(seed, foo,prob);

  return 0;
}

void show_rand(int seed, int n, float p){
  int i;
  float r;
  srand(seed);
  int c = 0;

  for(i = 0;i < n;i++){
    r = ((float) rand() / RAND_MAX);
    if(r < p){c++;}
    // printf("[%d] :: %f\n",i,r);
  }

  printf("Qnt total : %d\n< p : %d\n>= p : %d",n,c,n-c);
}
