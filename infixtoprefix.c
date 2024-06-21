#include <stdio.h>
#include <string.h>
#define max 50

void reverseString(char str[]) {
    int length = strlen(str);
    int start = 0;
    int end = length - 1;

    while (start < end) {
        // Swap characters at start and end
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;

        // Move start and end pointers towards each other
        start++;
        end--;
    }
}

typedef struct {
    char a[max];
    int top;
} stack;

stack s;
char infix[50], pfix[50];

void read() {
    printf("Enter the infix expression: ");
    scanf("%s", infix);
}

void push(char c) {
    if (s.top == max - 1) {
        printf("Stack is full\n");
        return;
    }
    s.a[++s.top] = c;
}

char pop() {
    if (s.top == -1) {
        printf("Underflow\n");
        return '\0';
    }
    return s.a[s.top--];
}

int isempty() {
    return s.top == -1;
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
    int p = 0, precedence;
    char e1, e2;
    for (int i = strlen(infix) - 1; i >= 0; i--) {
        e1 = infix[i];
        switch (e1) {
            case ')':
                push(e1);
                break;
            case '(':
                while ((e2 = pop()) != ')') {
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
                        } else {
                            break;
                        }
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

    // Reverse the pfix string before printing
    reverseString(pfix);

    printf("The prefix expression is: %s\n", pfix);
}

int main() {
    s.top = -1;
    int ch;
    do {
        read();
        contopfix();
        printf("Do you wish to continue? 1-yes 2-no: ");
        scanf("%d", &ch);
    } while (ch == 1);
    return 0;
}