/*Write an algorithm to simulate a queue using stacks. Use minimum
number of stacks to simulate enqueue() and dequeue().*/
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
int queue1[MAXSIZE];
int queue2[MAXSIZE];
int front1 = -1;
int front2 = -1;
int rear1=-1;
int rear2=-1;
int size1=0;
int size2=0;

void enqueue(int queue[], int *front, int *rear, int *size, int data) {
    if (*size == MAXSIZE) {
        printf("queue is full");
        return;
    }
    if (*front==-1)
        *front=0;
    *rear = (*rear+1)%MAXSIZE;
    queue[*rear]=data;
    (*size)++;
}

int dequeue(int queue[], int *front, int *rear, int *size) {
    if (*size==0) {
        printf("queue is empty");
        return -1;
    }
    int item=queue[*front];
    *front=(*front+1)%MAXSIZE;
    (*size)--;
    return item;
}

void push(int data) {
    enqueue(queue1, &front1, &rear1, &size1, data);
}

int pop() {
    if (size1 == 0 && size2 == 0) {
        printf("stack is empty");
        return -1;
    }

    if (size1 == 0) {
        while (size2 > 1) {
            int k= dequeue(queue2, &front2, &rear2, &size2);
            enqueue(queue1, &front1, &rear1, &size1,k);
        }
        return dequeue(queue2, &front2, &rear2, &size2);
    } else {
        while (size1 > 1) {
            int k= dequeue(queue1, &front1, &rear1, &size1);
            enqueue(queue2, &front2, &rear2, &size2, k);
        }
        return dequeue(queue1, &front1, &rear1, &size1);
    }
}

int main() {
    push(10);
    push(20);
    push(30);

    printf("%d\n", pop());
    printf("%d\n", pop());
    printf("%d\n", pop());

    return 0;
}

