#include <stdio.h>
#include <stdlib.h>
typedef struct N {
    int data;
    struct N* next;
} node;
void push(node* a, node** stack)
{
    a->next = *stack;
    *stack = a;
}
int top(node* stack)
{
    return stack->data;
}
void pop(node** stack)
{
    if (*stack == NULL)
        return;
    *stack = (*stack)->next;
}
int main(void)
{
    node* stack = (node*)malloc(sizeof(node));
    stack = NULL;
    node* a = (node*)malloc(sizeof(node));
    a->data = 1;
    a->next = NULL;
    push(a, &stack);
    a = (node*)malloc(sizeof(node));
    a->data = 3;
    a->next = NULL;
    push(a, &stack);
    a = (node*)malloc(sizeof(node));
    a->data = 4;
    a->next = NULL;
    push(a, &stack);
    while (stack != NULL) {
        printf("%d ", top(stack));
        pop(&stack);
    }
    return 0;
}
