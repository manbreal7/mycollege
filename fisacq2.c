#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct Stack {
    int top;
    int array[MAX];
};

void initialize(struct Stack *stack) {
    stack->top = -1;
}

int isFull(struct Stack* stack) {
    return stack->top == MAX - 1;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

void push(struct Stack* stack, char item) {
    if (!isFull(stack)) {
        stack->array[++stack->top] = item;
    }
}

char pop(struct Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->array[stack->top--];
    }
    return '\0';
}

int countInvalidTags(char* input) {
    struct Stack stack;
    initialize(&stack);
    int count = 0;
    int length = strlen(input);
    for (int i = 0; i < length; i++) {
        if (input[i] == '<') {
            if (input[i + 1] != '/') {
                push(&stack, input[i]);
            } else {
                if (isEmpty(&stack)) {
                    count++;
                } else {
                    pop(&stack);
                }
            }
            while (input[i] != '>') i++;
        }
    }
    count += (stack.top + 1);
    return count;
}

int main() {
    struct Stack stack;
    initialize(&stack);
    char input[MAX];

    printf("Enter the string: ");
    fgets(input, MAX, stdin);

    input[strcspn(input, "\n")] = 0;

    printf("Count of invalid tags: %d\n", countInvalidTags(input));

    return 0;
}
