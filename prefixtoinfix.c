#include <stdio.h>
#include <string.h>

#define MAX 50

struct Stack
{
    char arr[MAX][MAX];
    int top;
} s;

void push(char *str)
{
    strcpy(s.arr[++s.top], str);
}

char *pop()
{
    return s.arr[s.top--];
}

void main()
{
    int i;
    s.top = -1;
    char prefix[MAX], infix[MAX];
    char op1[20], op2[20], ch[2];
    printf("Enter prefix expression:\n");
    gets(prefix);

    for (i = strlen(prefix) - 1; i >= 0; i--)
    {
        ch[0] = prefix[i];
        ch[1] = '\0';
        if (ch[0] == '+' || ch[0] == '-' || ch[0] == '*' || ch[0] == '/')
        {
            strcpy(op1, pop());
            strcpy(op2, pop());
            strcpy(infix, "(");
            strcat(infix, op1);
            strcat(infix, ch);
            strcat(infix, op2);
            strcat(infix, ")");
            push(infix);
        }
        else
        {
            push(ch);
        }
    }
    printf("Fully parenthesized infix expression:\n");
    printf("%s\n", pop());
}

