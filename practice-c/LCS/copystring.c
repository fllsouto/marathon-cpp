#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void teste(int, char*);
void strip_first_char(char*);

int main(){

  char str[]   = "testewaka";
  int str_len = (unsigned)strlen(str);
  int i;
  char foo[] = "";
  for(i = 0; i < str_len; i++){
    printf ("%s :: %u\n",str + i, (unsigned)strlen(str + i));
  }


  return 0;
}

// void strip_first_char(char* o_str){
//   int lgt = strlen(o_str) - 1;
//   char* n_str = malloc

// }

void teste(int f, char* str){
  printf("flag : %d\n",f);
  printf("Testando : %s\n",str);
  printf ("Tamanho : %u,",(unsigned)strlen(str));
}