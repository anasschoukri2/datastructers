#include <stdio.h>
#include <stdlib.h>
typedef struct Linkedlist {
    int data;
    struct Linkedlist* next;
} node;
node* insertfront(node* a, node* linkedlist)
{
    a->next = linkedlist;
    linkedlist = a;
    return a;
}
node* insertback(node* a, node* linkedlist)
{
    if (linkedlist == NULL) {
        return a;
    }
    node* rear;
    node* walker;
    walker = linkedlist;
    while (walker != NULL) {
        rear = walker;
        walker = walker->next;
    }
    rear->next = a;
    return linkedlist;
}
node* insertinorder(node* a, node* linkedlist)
{
    if (linkedlist == NULL) {
        return a;
    }
    if (linkedlist->data > a->data) {
        a->next = linkedlist;
        linkedlist = a;
        return a;
    }
    node* rear;
    node* walker;
    rear = linkedlist;
    walker = linkedlist;
    while (walker != NULL) {
        if (walker->data > a->data) {
            rear->next = a;
            a->next = walker;
            return linkedlist;
        }
        rear = walker;
        walker = walker->next;
    }
    rear->next = a;
    return linkedlist;
}
void printList(node* Node)
{
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
}
int main()
{
    node* linkedlist = (node*)malloc(sizeof(node));
    linkedlist = NULL;
    node* a = (node*)malloc(sizeof(node));
    a->next = NULL;
    a->data = 1;
    linkedlist = insertback(a, linkedlist);
    a = (node*)malloc(sizeof(node));
    a->next = NULL;
    a->data = 52;
    linkedlist = insertinorder(a, linkedlist);
    a = (node*)malloc(sizeof(node));
    a->next = NULL;
    a->data = 9;
    linkedlist = insertinorder(a, linkedlist);
    printList(linkedlist);
    return 0;
}
