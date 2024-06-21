#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int front, rear, size;
    unsigned capacity;
    int* array;
};

struct Queue* createQueue(unsigned capacity)
{
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

int isFull(struct Queue* queue)
{
    return (queue->size == queue->capacity);
}

int isEmpty(struct Queue* queue)
{
    return (queue->size == 0);
}

void enqueue(struct Queue* queue, int item)
{
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
}

int dequeue(struct Queue* queue)
{
    if (isEmpty(queue))
        return -1;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

int front(struct Queue* queue)
{
    if (isEmpty(queue))
        return -1;
    return queue->array[queue->front];
}

int size(struct Queue* queue)
{
    return queue->size;
}

struct Stack {
    struct Queue* q1;
    struct Queue* q2;
};

void push(struct Stack* stack, int x)
{
    enqueue(stack->q2, x);
    while (!isEmpty(stack->q1)) {
        enqueue(stack->q2, front(stack->q1));
        dequeue(stack->q1);
    }
    struct Queue* q = stack->q1;
    stack->q1 = stack->q2;
    stack->q2 = q;
}

void pop(struct Stack* stack)
{
    if (isEmpty(stack->q1))
        return;
    dequeue(stack->q1);
}

int top(struct Stack* stack)
{
    if (isEmpty(stack->q1))
        return -1;
    return front(stack->q1);
}

int main()
{
    struct Stack* s = (struct Stack*)malloc(sizeof(struct Stack));
    s->q1 = createQueue(100);
    s->q2 = createQueue(100);
    push(s, 1);
    push(s, 2);
    push(s, 3);
    printf("current size: %d\n", size(s->q1));
    printf("%d\n", top(s));
    pop(s);
    printf("%d\n", top(s));
    pop(s);
    printf("%d\n", top(s));
    printf("current size: %d\n", size(s->q1));
    return 0;
}