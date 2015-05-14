#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(A,B) (((A) > (B))? (A) : (B))


void free_matrix(int** , int);
void show_matrix(int**, int, int);
void calculate_L_vector(int**, char*, int, char*, int, int*);
void calculate_right_LCS_matrix(int** ,char*, int, char*, int);
void initialize_right_LCS_matrix(int**, int , int);
void calculate_right_LCS(char *,char *);
char* get_string();

int main(){
  
  char *word1 = NULL;
  char *word2 = NULL;

  word1 = get_string();
  word2 = get_string();

  calculate_right_LCS(word1, word2);
  printf("\n");
  return 0;
}

void free_matrix(int** v, int m){
  int i;
  for(i = 0; i < m; i++){
      free(v[i]);
  }
  free(v);
}

void show_matrix(int** v,int m,int n){
  int i,j;
  printf ("\n");
  for(i = 0; i < m; i++){
    for(j = 0; j < n; j++){
      printf("%d ",v[i][j]);
    }
    printf ("\n");
  }
    printf ("-----------------------------------------------------------------");
    printf ("\n");
}

void show_L_vector(int* l,char* X, int x_size, char* Y){
  int i;
  for(i = 0; i < x_size; i++){ printf("%s --- %s\nL[%d] : %d\n", X + i, Y, i, l[i]); }
}


void calculate_L_vector(int**right_c, char* X, int x_size, char* Y, int y_size, int* vectorL){
  int i;
  for(i = 0; i < x_size; i++){ vectorL[i] = right_c[i][0]; }
}

void calculate_right_LCS_matrix(int** right_c, char* X, int x_size, char* Y, int y_size){
  int i,j;
  for(i = x_size - 1; i >= 0; i--){
    for(j = y_size - 1; j >= 0; j--){
      if(X[i] == Y[j]){
        right_c[i][j] = right_c[i+1][j+1] + 1;
      }else{
        right_c[i][j] = MAX(right_c[i+1][j], right_c[i][j+1]);
      }
    }
  }
}

void initialize_right_LCS_matrix(int** right_c, int m, int n){
  int i,j;
  for(i = 0; i < m; i++){ right_c[i][n-1] = 0; }
  for(j = 0; j < n; j++){ right_c[m-1][j] = 0; }
}

void calculate_right_LCS(char* wordX,char* wordY){
  int x_size = (unsigned)strlen(wordX);
  int y_size = (unsigned)strlen(wordY);
  int m = x_size + 1;
  int n = y_size + 1;
  int i,j;
  int llcs ;
  int rlcs ;
  int **right_c;
  int *vectorL;

  vectorL = malloc(x_size*sizeof(int));
  right_c = malloc(m*sizeof(int *));

  for(i = 0; i < m; i++){
    right_c[i] = malloc(n*sizeof(int));
  }

  initialize_right_LCS_matrix(right_c, m,n);
  calculate_right_LCS_matrix(right_c, wordX, x_size, wordY, y_size);
  calculate_L_vector(right_c, wordX, x_size, wordY, y_size, vectorL);
  show_L_vector(vectorL,wordX, x_size, wordY);


  show_matrix(right_c, m,n); 
  free_matrix(right_c, m);
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
