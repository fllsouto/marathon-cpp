#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(A,B) (((A) > (B))? (A) : (B))

void show_vector(int* ,int );
void initialize_right_LCS_vector(int* , int );
int* lLCS(char*, int, char*, int);
char* get_string();

int main(){
  
  char *word1 = NULL;
  char *word2 = NULL;
  word1 = get_string();
  word2 = get_string();
  int word1_lenght = (unsigned)strlen(word1);
  int word2_lenght = (unsigned)strlen(word2);
  int *L;

  L = lLCS(word1, word1_lenght, word2, word2_lenght);
  show_vector(L,(unsigned)strlen(word1));

  printf("\n");
  free(L);
  free(word1);
  free(word2);
  return 0;
}

void show_vector(int* v,int n){
  int i;
  printf("\nL = [");
  for(i = 1; i <= n; i++){ printf(" %d",v[i]); }
  printf(" ]\n");
}

void initialize_right_LCS_vector(int* right_v, int m){
  int i;
  for(i = 0; i < m; i++){ right_v[i] = 0; }
}

int* lLCS(char* x, int n, char* y, int m){
  int i,j;
  int a,b,c;
  int r;
  int *L = malloc((n+1)*sizeof(int));
  int *right_v = malloc((m+1)*sizeof(int));
  initialize_right_LCS_vector(right_v, n);
  L[0] = 0;
  
  for(i = n - 1; i >= 0; i--){
    a = 0;
    b = 0;
    for(j = m - 1; j >= 0; j--){
      c = right_v[j];
      if(x[i] == y[j]){
        a = b + 1;
      }else{
        a = MAX(a, c);
      }
      b = c;
      right_v[j] = a;
    }
    right_v[j+1] = a;
    L[i+1] = right_v[j+1];
  }
  free(right_v);
  return L;
}


char* get_string(char* str){
  size_t len = 0;
  ssize_t read;

  printf("Insira uma sequencia de caracteres : ");
  if(getline(&str, &len, stdin) != -1){
    size_t ln = strlen(str); 
    if (ln > 0 && str[ln-1] == '\n') {str[--ln] = '\0';}
    printf("Palavra lida : %s\n",str);
    return str;
  }else{
    printf("Erro! Programa Abortado\n");
    exit(EXIT_FAILURE);
  }
}