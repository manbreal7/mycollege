#include <stdio.h>
#include <string.h>
#define max 50

typedef struct {
    char a[max];
    int top;
} stack;

stack s;
char infix[50], pfix[50];

void read() {
    printf("enter the infix expression\n");
    scanf("%s", infix);
}

void push(char c) {
    if (s.top == max - 1) {
        printf("stack is full\n");
        return;
    }
    s.a[++s.top] = c;
}

char pop() {
    if (s.top == -1) {
        printf("underflow\n");
        return '\0';
    }
    return s.a[s.top--];
}

int isempty() {
    if (s.top == -1) {
        return 1;
    } else
        return 0;
}

int prec1(char symbol) {
    switch (symbol) {
        case '/':
        case '*':
            return 3;
        case '+':
        case '-':
            return 2;
        case '(':
            return 0;
        default:
            return -1;
    }
}

void contopfix() {
    int l, precedence, p;
    p = 0;
    char e1, e2;
    for (int i = 0; infix[i] != '\0'; i++) {
        e1 = infix[i];
        switch (e1) {
            case '(':
                push(e1);
                break;
            case ')':
                while ((e2 = pop()) != '(') {
                    pfix[p++] = e2;
                }
                break;
            case '+':
            case '-':
            case '*':
            case '/':
                if (!isempty()) {
                    precedence = prec1(e1);
                    e2 = pop();
                    while (precedence <= prec1(e2)) {
                        pfix[p++] = e2;

                        if (!isempty()) {
                            e2 = pop();
                        } else
                            break;
                    }
                    if (precedence > prec1(e2)) {
                        push(e2);
                    }
                }
                push(e1);
                break;
            default:
                pfix[p++] = e1;
                break;
        }
    }
    while (!isempty()) {
        pfix[p++] = pop();
    }
    pfix[p] = '\0';
    printf("the postfix expression is: %s\n", pfix);
}

int main() {
   s.top = -1;
    char ch;
    do {
        read();
        contopfix();
        printf("do you wish to continue? (y/n): ");
        scanf(" %c", &ch);
    } while (ch == 'y' || ch == 'Y');
    return 0;
}
