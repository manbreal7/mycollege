#include <stdio.h>
#define max 50

typedef struct {
    int top;
    int a[max];
} stack;

stack s;
char pfix[50];

int operate(int x, int y, char c) {
    switch(c) {
        case '+': return x + y;
        case '-': return x - y;
        case '/': return x / y;
        case '*': return x * y;
    }
    return 0;
}

void push(int n) {
    if(s.top == max - 1) {
        printf("stack is full");
        return;
    }
    s.a[++s.top] = n;
}

int pop() {
    if(s.top == -1) {
        printf("underflow");
        return -1;
    } else {
        return s.a[s.top--];
    }
}

void evalpfix() {
    int op1, op2, result;
    printf("enter postfix expression: ");
    scanf("%s", pfix);

    for(int i = 0; pfix[i] != '\0'; i++) {
        if(pfix[i] == '+' || pfix[i] == '-' || pfix[i] == '/' || pfix[i] == '*') {
            op2 = pop();
            op1 = pop();
            result = operate(op1, op2, pfix[i]);
            push(result);
        } else {
            push(pfix[i] - '0');
        }
    }

    printf("Result: %d\n", pop());
}

int main() {
    s.top = -1;
    char ch;
    do {
        evalpfix();
        printf("do you wish to continue? (y/n): ");
        scanf(" %c", &ch);
    } while(ch == 'y' || ch == 'Y');

    return 0;
}
