#include <stdio.h>
int heap[1024];
int si=0;
void insert(int h){
    heap[si]=h;
    int j=si;
    si++;
    while(j>0&&heap[j]>heap[j/2]){
      int t=heap[j];
      heap[j]=heap[j/2];
      heap[j/2]=t;
      j/=2;
    }
}
void pop(){
  if(si==0)return ;
 heap[0]=heap[si-1];
 si--;
 int j=0;
 while(2*j+2<=si){
      if(heap[j]<heap[2*j+1]){
          int t=heap[j];
          heap[j]=heap[2*j+1];
          heap[2*j+1]=t;
          j=2*j+1;
      }
      if(heap[j]<heap[2*j+2]&&2*j+2<=si){
          int t=heap[j];
          heap[j]=heap[2*j+2];
          heap[2*j+2]=t;
          j=2*j+2;
      }
 }
}
int main(void) {
  insert(1);
  printf("%d ",heap[0]);
  insert(2);
  printf("%d ",heap[0]);
  insert(5);
  printf("%d ",heap[0]);
  insert(10);
  printf("%d ",heap[0]);
  pop();
  printf("%d ",heap[0]);
  pop();
  printf("%d ",heap[0]);
  pop();
  printf("%d ",heap[0]);
  pop();
  if(si)
  printf("%d ",heap[0]);
  return 0;
}
