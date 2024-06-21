#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createList() {
    printf("Enter an element (or -1 to stop): ");
    int elem;
    scanf("%d", &elem);
    if (elem == -1) {
        return NULL;
    }

    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = elem;
    temp->next = createList();
    return temp;
}

void traverse(struct Node* temp) {
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = createList();
    printf("Linked List elements: ");
    traverse(head);
    printf("\n");

    return 0;
}
