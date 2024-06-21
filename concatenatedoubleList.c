#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode) {
        newNode->data = data;
        newNode->prev = NULL;
        newNode->next = NULL;
    }
    return newNode;
}

struct Node* concatenateLists(struct Node* X1, struct Node* X2) {
    if (X1 == NULL) {
        return X2;
    }
    if (X2 == NULL) {
        return X1;
    }

    struct Node* current = X1;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = X2;
    X2->prev = current;

    return X1;
}

void traverseList(struct Node* head) {
    printf("Concatenated Doubly Linked List: ");
    struct Node* current = head;
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

struct Node* inputList() {
    struct Node* head = NULL;
    int num, data;

    printf("Enter the number of elements in the list: ");
    scanf("%d", &num);

    for (int i = 1; i <= num; i++) {
        printf("Enter element %d: ", i);
        scanf("%d", &data);
        struct Node* newNode = createNode(data);
        if (head == NULL) {
            head = newNode;
        } else {
            struct Node* current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
            newNode->prev = current;
        }
    }

    return head;
}

int main() {
    struct Node* X1 = NULL;
    struct Node* X2 = NULL;

    printf("Enter elements for the first list (X1):\n");
    X1 = inputList();

    printf("Enter elements for the second list (X2):\n");
    X2 = inputList();

    X1 = concatenateLists(X1, X2);

    traverseList(X1);

    return 0;
}
