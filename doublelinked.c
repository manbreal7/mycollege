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

struct Node* deleteRear(struct Node* head) {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
    } else {
        if (head->next == NULL) {
            free(head);
            return NULL;
        } else {
            struct Node* current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->prev->next = NULL;
            free(current);
        }
    }
    return head;
}

struct Node* insertAtPosition(struct Node* head, int data, int position) {
    struct Node* newNode = createNode(data);
    if (position < 1) {
        printf("Invalid position. Element not inserted.\n");
    } else if (position == 1) {
        newNode->next = head;
        if (head != NULL) {
            head->prev = newNode;
        }
        return newNode;
    } else {
        struct Node* current = head;
    
        while (position > 2) {
            current = current->next;
            position--;
        }
        if (current == NULL) {
            printf("Position is out of range. Element not inserted.\n");
        } else {
            newNode->next = current->next;
            newNode->prev = current;
            current->next = newNode;
            if (newNode->next != NULL) {
                newNode->next->prev = newNode;
            }
        }
    }
    return head;
}

struct Node* deleteAtPosition(struct Node* head, int position) {
    if (position < 1) {
        printf("Invalid position. Element not deleted.\n");
    } else if (position == 1) {
        struct Node* temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        free(temp);
    } else {
        struct Node* current = head;
        int i = 1;
        while (i < position && current != NULL) {
            current = current->next;
            i++;
        }
        if (current == NULL) {
            printf("Position is out of range. Element not deleted.\n");
        } else {
            current->prev->next = current->next;
            if (current->next != NULL) {
                current->next->prev = current->prev;
            }
            free(current);
        }
    }
    return head;
}

struct Node* insertAfterElement(struct Node* head, int data, int key) {
    struct Node* newNode = createNode(data);
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == key) {
            newNode->next = current->next;
            newNode->prev = current;
            if (current->next != NULL) {
                current->next->prev = newNode;
            }
            current->next = newNode;
            return head;
        }
        current = current->next;
    }
    printf("Element not found. Element not inserted.\n");
    return head;
}

struct Node* insertBeforeElement(struct Node* head, int data, int key) {
    struct Node* newNode = createNode(data);
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == key) {
            if (current->prev != NULL) {
                current->prev->next = newNode;
                newNode->prev = current->prev;
            } else {
                head = newNode;
            }
            newNode->next = current;
            current->prev = newNode;
            return head;
        }
        current = current->next;
    }
    printf("Element not found. Element not inserted.\n");
    return head;
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

struct Node* reverseList(struct Node* head) {
    struct Node* current = head;
    struct Node* temp = NULL;
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp != NULL) {
        head = temp->prev;
    }
    return head;
}

int main() {
    struct Node* head = NULL;
    int choice, data, position, key;

    do {
        printf("\nMenu:\n");
        printf("1. Insert an element at the rear end\n");
        printf("2. Delete an element from the rear end\n");
        printf("3. Insert an element at a given position\n");
        printf("4. Delete an element from a given position\n");
        printf("5. Insert an element after another element\n");
        printf("6. Insert an element before another element\n");
        printf("7. Traverse the list\n");
        printf("8. Reverse the list\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert at the rear end: ");
                scanf("%d", &data);
                head = insertRear(head, data);
                break;

            case 2:
                head = deleteRear(head);
                break;

            case 3:
                printf("Enter the element to insert: ");
                scanf("%d", &data);
                printf("Enter the position to insert: ");
                scanf("%d", &position);
                head = insertAtPosition(head, data, position);
                break;

            case 4:
                printf("Enter the position to delete: ");
                scanf("%d", &position);
                head = deleteAtPosition(head, position);
                break;

            case 5:
                printf("Enter the element to insert: ");
                scanf("%d", &data);
                printf("Enter the element to insert after: ");
                scanf("%d", &key);
                head = insertAfterElement(head, data, key);
                break;

            case 6:
                printf("Enter the element to insert: ");
                scanf("%d", &data);
                printf("Enter the element to insert before: ");
                scanf("%d", &key);
                head = insertBeforeElement(head, data, key);
                break;

            case 7:
                traverseList(head);
                break;

            case 8:
                head = reverseList(head);
                break;

            case 0:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 0);

}
