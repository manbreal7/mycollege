#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = newNode;
    newNode->prev = newNode;
    return newNode;
}

struct Node* insertFront(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    newNode->next = head;
    newNode->prev = head->prev;
    head->prev->next = newNode;
    head->prev = newNode;
    return newNode;
}

struct Node* deleteElement(struct Node* head, int key) {
    if (head == NULL) {
        return head;
    }

    struct Node* current = head;
    do {
        if (current->data == key) {
            if (current->next == current) {
                free(current);
                return NULL;
            }

            current->prev->next = current->next;
            current->next->prev = current->prev;

            if (current == head) {
                head = current->next;
            }

            free(current);
            return head;
        }
        current = current->next;
    } while (current != head);

    return head;
}

void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* current = head;
    do {
        printf("%d <-> ", current->data);
        current = current->next;
    } while (current != head);

    printf("... (circular)\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data, key;

    do {
        printf("\nMenu:\n");
        printf("1. Insert an element\n");
        printf("2. Delete an element\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &data);
                head = insertFront(head, data);
                displayList(head);
                break;

            case 2:
                if (head == NULL) {
                    printf("List is empty. Nothing to delete.\n");
                } else {
                    printf("Enter the element to delete: ");
                    scanf("%d", &key);
                    head = deleteElement(head, key);
                    displayList(head);
                }
                break;

            case 0:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 0);

    return 0;
}
