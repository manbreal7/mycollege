#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* insert(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    if (head == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        head = newNode;
    } else {
        struct Node* last = head->prev;
        newNode->next = head;
        head->prev = newNode;
        newNode->prev = last;
        last->next = newNode;
    }
    return head;
}

struct Node* deleteNode(struct Node* head, int key) {
    if (head == NULL)
        return NULL;

    struct Node* current = head;
    struct Node* toDelete = NULL;

    // If the node to be deleted is the head
    if (current->data == key) {
        toDelete = current;
        head = current->next;
    } else {
        while (current->next != head) {
            if (current->next->data == key) {
                toDelete = current->next;
                current->next = toDelete->next;
                toDelete->next->prev = current;
                break;
            }
            current = current->next;
        }
    }

    if (toDelete == NULL) {
        printf("Node with data %d not found.\n", key);
    } else {
        free(toDelete);
        printf("Node with data %d deleted successfully.\n", key);
    }

    return head;
}

// Function to print the doubly linked circular list
void printList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* current = head;
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data, key;

    do {
        printf("\n1. Insert an element\n");
        printf("2. Delete an element\n");
        printf("3. Print the list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data to be inserted: ");
                scanf("%d", &data);
                head = insert(head, data);
                printf("Element %d inserted successfully.\n", data);
                break;
            case 2:
                if (head == NULL) {
                    printf("List is empty. No elements to delete.\n");
                } else {
                    printf("Enter the data to be deleted: ");
                    scanf("%d", &key);
                    head = deleteNode(head, key);
                }
                break;
            case 3:
                printf("The list is: ");
                printList(head);
                break;
            case 4:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (1);

    return 0;
}
