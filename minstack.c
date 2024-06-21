#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int arr[MAX];
    int top;
} Stack;

void init(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    if (s->top == -1)
        return 1;
    return 0;
}

int isFull(Stack *s) {
    if (s->top == MAX - 1)
        return 1;
    return 0;
}

int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow");
        exit(1);
    }
    int x = s->arr[s->top];
    s->top--;
    return x;
}

void push(Stack *s, int x) {
    if (isFull(s)) {
        printf("Stack Overflow");
        exit(1);
    }
    s->top++;
    s->arr[s->top] = x;
}

typedef struct {
    Stack s;
    Stack min;
} SpecialStack;

int pop(SpecialStack *s) {
    if (isEmpty(&(s->s))) {
        printf("Stack Underflow");
        exit(1);
    }
    int x = pop(&(s->s));
    pop(&(s->min));
    return x;
}

void push(SpecialStack *s, int x) {
    push(&(s->s), x);
    if (isEmpty(&(s->min)) || x <= s->min.arr[s->min.top])
        push(&(s->min), x);
}

int getMin(SpecialStack *s) {
    if (isEmpty(&(s->min))) {
        printf("Stack Underflow");
        exit(1);
    }
    return s->min.arr[s->min.top];
}

int main() {
    SpecialStack s;
    init(&(s.s));
    init(&(s.min));

    push(&s, 3);
    push(&s, 5);
    push(&s, 2);
    push(&s, 1);

    printf("Minimum element in the stack: %d\n", getMin(&s));

    pop(&s);
    pop(&s);

    printf("Minimum element in the stack: %d\n", getMin(&s));

    return 0;
}