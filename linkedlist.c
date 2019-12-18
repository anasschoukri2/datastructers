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
void Delete(int id, node** linkedlist)
{
    if (*linkedlist == NULL)
        return;
    while ((*linkedlist) != NULL && (*linkedlist)->data == id) {
        *linkedlist = (*linkedlist)->next;
    }
    node* walker = *linkedlist;
    node* rear = *linkedlist;
    while (walker != NULL) {
        if (walker->data == id) {
            rear->next = walker->next;
        }
        rear = walker;
        walker = walker->next;
    }
}
void search(int id, node* linkedlist)
{
    node* walker = linkedlist;
    while (walker != NULL) {
        if (walker->data == id) {
            printf("Found!\n");
            return;
        }
        walker = walker->next;
    }
    printf("NOT Found!\n");
}
void printList(node* Node)
{
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}
int main()
{
    node* linkedlist = (node*)malloc(sizeof(node));
    linkedlist = NULL;
    node* a = (node*)malloc(sizeof(node));
    a->next = NULL;
    a->data = 100;
    linkedlist = insertinorder(a, linkedlist);
    a = (node*)malloc(sizeof(node));
    a->next = NULL;
    a->data = 52;
    linkedlist = insertinorder(a, linkedlist);
    a = (node*)malloc(sizeof(node));
    a->next = NULL;
    a->data = 9;
    linkedlist = insertinorder(a, linkedlist);
    a = (node*)malloc(sizeof(node));
    a->next = NULL;
    a->data = 1;
    linkedlist = insertinorder(a, linkedlist);
    a = (node*)malloc(sizeof(node));
    a->next = NULL;
    a->data = 8888;
    linkedlist = insertinorder(a, linkedlist);
    search(1, linkedlist);
    printList(linkedlist);
    Delete(1, &linkedlist);
    Delete(9, &linkedlist);
    Delete(8888, &linkedlist);
    search(1, linkedlist);
    printList(linkedlist);
    return 0;
}
