#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *push(struct Node *head, int new_data) {
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));

    new_node->data = new_data;

    new_node->next = head;

    return new_node;
}

int search(struct Node *head, int x) {
    struct Node *current = head;
    while (current != NULL) {
        if (current->data == x)
            return 1;
        current = current->next;
    }
    return 0;
}

void printList(struct Node *node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

struct Node *symmetricDifference(struct Node *A, struct Node *B) {
    struct Node *result = NULL;
    struct Node *temp1 = A;
    struct Node *temp2 = B;

    while (temp1 != NULL) {
        if (!search(B, temp1->data))
            result = push(result, temp1->data);
        temp1 = temp1->next;
    }

    while (temp2 != NULL) {
        if (!search(A, temp2->data))
            result = push(result, temp2->data);
        temp2 = temp2->next;
    }

    return result;
}

void freeList(struct Node *node) {
    struct Node *temp;
    while (node != NULL) {
        temp = node;
        node = node->next;
        free(temp);
    }
}

int main() {
    struct Node *A = NULL;
    struct Node *B = NULL;
    struct Node *result = NULL;
    int num, val;
    printf("Enter the number of elements for the first list: ");
    scanf("%d", &num);
    printf("Enter the elements for the first list:\n");
    for (int i = 0; i < num; i++) {
        scanf("%d", &val);
        A = push(A, val);
    }
    printf("Enter the number of elements for the second list: ");
    scanf("%d", &num);
    printf("Enter the elements for the second list:\n");
    for (int i = 0; i < num; i++) {
        scanf("%d", &val);
        B = push(B, val);
    }
    printf("Singly Linked List A: ");
    printList(A);
    printf("\nSingly Linked List B: ");
    printList(B);
    result = symmetricDifference(A, B);
    printf("\nSymmetric Difference: ");
    printList(result);
    freeList(A);
    freeList(B);
    freeList(result);

    return 0;
}
