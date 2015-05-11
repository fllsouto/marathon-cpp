#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(A,B) (((A) > (B))? (A) : (B))

int **left_c;

void left_memoized_LCS(int , int);
void right_memoized_LCS(int**, int , int);
int lookup_LCS(int** ,char*, int, char*, int);
void show_matrix(int**, int, int);
void free_matrix(int** , int , int );
void calculate_right_LCS(char *,char *);

int main(){
  
  char word1[] = "ABCBDAB";
  char word2[] = "BDCABA";
  int x_l = (unsigned)strlen(word1);
  int i;
  for(i = 0; i < x_l; i++){
    calculate_right_LCS(word1 + i, word2);
  }
  // calculate_right_LCS("B", word2);
  printf("\n");
  return 0;
}



int left_lookup_LCS(char* X, int m, char* Y, int n){
  int i,j;
  printf("\n");
  for(i = 1; i < m; i++){
    for(j = 1; j < n; j++){
      if(X[i-1] == Y[j-1]){
        left_c[i][j] = left_c[i-1][j-1] + 1;
      }else{
        left_c[i][j] = MAX(left_c[i-1][j], left_c[i][j-1]);
      }
    }
  }
  return left_c[i-1][j-1];
}

int right_lookup_LCS(int** right_c, char* X, int x_size, char* Y, int y_size){
  int i,j;
  for(i = x_size - 1; i >= 0; i--){
    for(j = y_size - 1; j >= 0; j--){
      if(X[i] == Y[j]){
        printf("(%d,%d) %c :: %c\n", i,j,X[i],Y[j]);
        right_c[i][j] = right_c[i+1][j+1] + 1;
      }else{
        right_c[i][j] = MAX(right_c[i+1][j], right_c[i][j+1]);
      }
    }
  }
  return right_c[i+1][j+1];
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
    printf ("--------------------");
    printf ("\n");
}

void left_memoized_LCS(int m, int n){
  int i,j;
  for(i = 0; i < m; i++){ left_c[i][0] = 0; }
  for(j = 0; j < n; j++){ left_c[0][j] = 0; }
}
void right_memoized_LCS(int** right_c, int m, int n){
  int i,j;
  for(i = 0; i < m; i++){ right_c[i][n-1] = 0; }
  for(j = 0; j < n; j++){ right_c[m-1][j] = 0; }
}

void free_matrix(int** v, int m, int n){
  int i;
  for(i = 0; i < m; i++){
      free(v[i]);
  }
  free(v);
}
void calculate_right_LCS(char* wordX,char* wordY){
  int x_size = (unsigned)strlen(wordX);
  int y_size = (unsigned)strlen(wordY);
  printf("Ysize : %d\nXsize : %d\n", y_size,x_size);
  int m = x_size + 1;
  int n = y_size + 1;
  int i,j;
  int llcs ;
  int rlcs ;
  int **right_c;


  // printf("Palavra X : %s \nPalavra Y : %s\n", wordX,wordY);
  // left_c = malloc(m*sizeof(int *));
  right_c = malloc(m*sizeof(int *));

  for(i = 0; i < m; i++){
    left_c[i] = malloc(n*sizeof(int));
    // right_c[i] = malloc(n*sizeof(int));
  }
  // left_memoized_LCS(m,n);
  right_memoized_LCS(right_c, x_size,y_size);
  // llcs = left_lookup_LCS(wordX, m, wordY, n);
  rlcs = right_lookup_LCS(right_c, wordX, x_size, wordY, y_size);
  printf("\nX : %s\n", wordX);
  printf("Y : %s\n", wordY);
  printf("RLCS : %d\n", rlcs);
  show_matrix(right_c, m,n); 
  // printf("\nLLCS encontrado : %d\n", llcs);
  // show_matrix(left_c, m,n); 
  // memoized_LCS(wordX, wordY);

  free_matrix(left_c, m, n);
  free_matrix(right_c, m,n);
}