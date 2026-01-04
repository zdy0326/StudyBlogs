#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ElemType;

typedef struct Node {
    ElemType data;
    struct Node* next;
}Node;

typedef struct {
    Node* front;
    Node* rear;
}Queue;

void InitQueue(Queue* q) {
    q->front = q->rear = NULL;
}

bool isEmpty(Queue* q) {
    return q->front == NULL;
}

bool EnQueue(Queue* q, ElemType x) {
    Node* p = (Node*)malloc(sizeof(Node));
    if (!p) return false;

    p->data = x;
    p->next = NULL;

    if (isEmpty(q)) {
        q->front = q->rear = p;
    } else {
        q->rear->next = p;
        q->rear = p;
    }
    return true;
}

bool DeQueue(Queue* q, ElemType* x) {
    if (isEmpty(q)) return false;

    Node* p = q->front;
    *x = p->data;
    q->front = p->next;

    if (q->front == NULL)
        q->rear = NULL;

    free(p);
    return true;
}

int main() {
    Queue q;
    InitQueue(&q);

    for (int i = 0; i < 10; i++) {
        EnQueue(&q, i);
    }

    int x;
    while (!isEmpty(&q)) {
        DeQueue(&q, &x);
        printf("%d ", x);
    }

    return 0;
}