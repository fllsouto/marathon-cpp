#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* get_string();

int main(){
  
  char *word1 = NULL;
  word1 = get_string();

  printf("\n");
  return 0;
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