#include <stdio.h>
#include <stdlib.h>


struct list{
  int x;
  struct list *prox;
};

typedef struct list LinkedList;


void print_list(LinkedList *head, int size){
  int i = 0;
  LinkedList *tmp = head;
  for(i; i < size; i++){
    printf("[%d] :: %d",i,tmp->x);
    tmp = tmp->prox;
  }
}

LinkedList* add_node_nh(LinkedList *head,int val){

  LinkedList *node;

  node = malloc(sizeof(LinkedList));
  node->x = val;
  if(head != NULL){
    printf("null =! Val :: %d\n",val);
    node->prox = head->prox;
    head = node;
  }
  else{
    printf("null Val :: %d\n",val);
    node->prox = head;
    return node;
  }
}

int main(){
  LinkedList* foo = NULL;
  LinkedList* bar;

  int n, i;
  printf("Qnts nós : ");
  scanf("%d",&n);
  srand(n);
  for(i = 0; i < n; i++){
    foo = add_node_nh(foo,rand());
    // printf("[%d] : %d\n",i, foo->x);
  }

  bar = foo;
  while(bar != NULL){
    printf(">> %d\n",bar->x);
    bar = bar->prox;
  }

  // // foo = remove_from_list(foo);
  // print_list(foo,n);
  return 0;
}

// void add_node_h(LinkedList *head,int val){
//   printf ("Val : %d\n",val);
//   LinkedList *node;
//   node = malloc(sizeof(LinkedList));
//   node->prox = head->prox;
//   node->x = val;
//   head->prox = node;
// }

// LinkedList* add_node_nh(LinkedList *head,int val){

//   LinkedList *node;
//   node = malloc(sizeof(LinkedList));
//   node->x = val;
//   if(head != NULL){
//     node->prox = head->prox;
//     head = node;
//   }
//   else{
//     node->prox = NULL;
//     head = node;
//   }
//   return head;
// }

// LinkedList* remove_from_list(LinkedList *head){
//   LinkedList *tmp;
//   if(head == NULL){
//     return NULL;
//   }
//   else{
//     tmp = head;
//     head->prox = tmp->prox;
//     printf("Valor apagado : %d\n",tmp->x);
//     printf("Valor prox : %d\n",head->x);
//     free(tmp);
//     return head;
//   }
// }

// void print_list(LinkedList *head){
//   int i = 0;
//   LinkedList *temp;
//   temp = head;
//   printf("-------\n");
//   while(temp != NULL){
//     printf("[%d] :: %d\n", i,temp->x);
//     i++;
//     temp = temp->prox;
//   }
// }

// int main(){
//   LinkedList *foo = NULL;
//   int n, i;
//   printf("Qnts nós : ");
//   scanf("%d",&n);
//   srand(n);

//   for(i = 0; i < n; i++){
//     foo = add_node_nh(foo,rand());
//     printf("[%d] : %d\n",i, foo->x);
//   }

//   // foo = remove_from_list(foo);
//   print_list(foo);
//   return 0;
// }



