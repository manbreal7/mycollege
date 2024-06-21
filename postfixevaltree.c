#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Node {
    char data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int evaluate(struct Node* root) {
    if (root) {
        if (isdigit(root->data)) {
            return root->data - '0';
        } else {
            int left = evaluate(root->left);
            int right = evaluate(root->right);

            switch (root->data) {
                case '+':
                    return left + right;
                case '-':
                    return left - right;
                case '*':
                    return left * right;
                case '/':
                    return left / right;
            }
        }
    }

    return 0;
}

int main() {
    char postfix[100];
    printf("Enter a postfix expression: ");
    scanf("%s", postfix);

    struct Node* stack[100];
    int top = -1;

    for (int i = 0; postfix[i] != '\0'; i++) {
        struct Node* newNode = createNode(postfix[i]);

        if (isdigit(postfix[i])) {
            stack[++top] = newNode;
        } else {
            newNode->right = stack[top--];
            newNode->left = stack[top--];
            stack[++top] = newNode;
        }
    }

    int result = evaluate(stack[top]);
    printf("Result of the postfix expression: %d\n", result);

    return 0;
}
