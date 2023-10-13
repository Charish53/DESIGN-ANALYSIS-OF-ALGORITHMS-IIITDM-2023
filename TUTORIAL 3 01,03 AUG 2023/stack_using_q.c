/*QUESTION 4:Write an algorithm to simulate a stack using queues. Use minimum
number of queues to simulate push() and pop().*/
#include <stdio.h>

int stack1[100];
int stack2[100];
int top1 = -1;
int top2 = -1;

void push(int stack[], int* top, int data, int size) {
    if (*top == size - 1) {
        printf("Stack is full");
    } else {
        (*top)++;
        stack[*top] = data;
    }
}

int pop(int stack[], int* top) {
    if (*top == -1) {
        printf("Stack underflown");
        return -1;
    } else {
        int k = stack[*top];
        (*top)--;
        return k;
    }
}

int dequeue(int stack1[], int stack2[], int* top1, int* top2) {
    int k;
    if (*top1 == -1) {
        while (*top2 != -1) {
            push(stack1, top1, pop(stack2, top2), 10);
        }
        k = pop(stack1, top1);
    } else {
        while (*top1 != -1) {
            push(stack2, top2, pop(stack1, top1), 10);
        }
        k = pop(stack2, top2);
    }
    return k;
}

int main() {
    push(stack1, &top1, 3, 10);
    push(stack1, &top1, 4, 10);
    push(stack1, &top1, 7, 10);
    push(stack1, &top1, 9, 10);
    push(stack1, &top1, 5, 10);
    int k = dequeue(stack1, stack2, &top1, &top2);
    printf("%d\n", k);
    return 0;
}
