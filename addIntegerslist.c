#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* create(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode) {
        newNode->data = data;
        newNode->prev = NULL;
        newNode->next = NULL;
    }
    return newNode;
}

struct Node* insert(struct Node* head, int data) {
    struct Node* newNode = create(data);
    if (head == NULL) {
        return newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        return newNode;
    }
}

struct Node* addNumbers(struct Node* num1, struct Node* num2) {
    struct Node* result = NULL;
    int carry = 0;

    while (num1 != NULL || num2 != NULL || carry) {
        int sum = carry;

        if (num1 != NULL) {
            sum += num1->data;
            num1 = num1->next;
        }
        if (num2 != NULL) {
            sum += num2->data;
            num2 = num2->next;
        }

        carry = sum / 10;
        int digit = sum % 10;

        result = insert(result, digit);
    }

    return result;
}

void printList(struct Node* head) {
    if (head == NULL) {
        printf("0");
        return;
    }

    struct Node* current = head;
    while (current != NULL) {
        printf("%d", current->data);
        current = current->next;
    }
}

int main() {
    struct Node* num1 = NULL;
    struct Node* num2 = NULL;

    printf("Enter the first positive integer (one digit at a time, enter -1 to end): ");
    int digit;
    while (1) {
        scanf("%d", &digit);
        if (digit == -1) {
            break;
        }
        num1 = insertFront(num1, digit);
    }

    printf("Enter the second positive integer (one digit at a time, enter -1 to end): ");
    while (1) {
        scanf("%d", &digit);
        if (digit == -1) {
            break;
        }
        num2 = insertFront(num2, digit);
    }

    struct Node* sum = addNumbers(num1, num2);

    printf("Sum: ");
    printList(sum);

    while (num1 != NULL) {
        struct Node* temp = num1;
        num1 = num1->next;
        free(temp);
    }

    while (num2 != NULL) {
        struct Node* temp = num2;
        num2 = num2->next;
        free(temp);
    }

    while (sum != NULL) {
        struct Node* temp = sum;
        sum = sum->next;
        free(temp);
    }

    return 0;
}
