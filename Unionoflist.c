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

struct Node* insertRear(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    } else {
        struct Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
        return head;
    }
}

void traverseList(struct Node* head) {
    printf("Doubly Linked List: ");
    struct Node* current = head;
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int isInList(struct Node* head, int data) {
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == data) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

struct Node* unionLists(struct Node* X1, struct Node* X2) {
    struct Node* result = NULL;
    struct Node* current = X1;

    while (current != NULL) {
        result = insertRear(result, current->data);
        current = current->next;
    }

    current = X2;

    while (current != NULL) {
        if (!isInList(result, current->data)) {
            result = insertRear(result, current->data);
        }
        current = current->next;
    }

    return result;
}

struct Node* intersectLists(struct Node* X1, struct Node* X2) {
    struct Node* result = NULL;
    struct Node* current = X1;

    while (current != NULL) {
        if (isInList(X2, current->data) && !isInList(result, current->data)) {
            result = insertRear(result, current->data);
        }
        current = current->next;
    }

    return result;
}

int main() {
    struct Node* X1 = NULL;
    struct Node* X2 = NULL;

    printf("Enter elements for the first list (X1), and -1 to end:\n");
    int data;
    while (1) {
        scanf("%d", &data);
        if (data == -1) {
            break;
        }
        X1 = insertRear(X1, data);
    }

    printf("Enter elements for the second list (X2), and -1 to end:\n");
    while (1) {
        scanf("%d", &data);
        if (data == -1) {
            break;
        }
        X2 = insertRear(X2, data);
    }

    struct Node* unionResult = unionLists(X1, X2);
    printf("\nUnion of X1 and X2:\n");
    traverseList(unionResult);

    struct Node* intersectionResult = intersectLists(X1, X2);
    printf("\nIntersection of X1 and X2:\n");
    traverseList(intersectionResult);

    return 0;
}
