#include <stdio.h>
#include <stdlib.h>
typedef struct N{
  int data;
  struct N * next;
}node;
void push(node *a,node **queue){
    if(*queue==NULL){*queue=a;return ;}
    node * walker=*queue;
    while(walker->next!=NULL){
        walker=walker->next;
    }
    walker->next=a;
    
}
void pop(node ** queue){
  if(*queue==NULL){return ;}
  printf("%d", (*queue)->data);
  *queue=(*queue)->next;
}
int main(void) {
  node* queue= (node*)malloc(sizeof(node));
  queue = NULL;
  node* a = (node*)malloc(sizeof(node));
  a->data = 1;
  a->next = NULL;
  push(a, &queue);
  a = (node*)malloc(sizeof(node));
  a->data = 2;
  a->next = NULL;
  push(a, &queue);
  a = (node*)malloc(sizeof(node));
  a->data = 3;
  a->next = NULL;
  push(a, &queue);
  pop(&queue);
  pop(&queue);
  pop(&queue);
  pop(&queue);
  return 0;
}
