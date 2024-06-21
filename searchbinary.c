#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }

    if (key < root->data) {
        return search(root->left, key);
    }

    return search(root->right, key);
}

void inOrderTraversal(struct Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int data, key;

    do {
        printf("Enter an element to insert into the binary search tree (or enter -1 to exit): ");
        scanf("%d", &data);

        if (data != -1) {
            root = insert(root, data);
        }
    } while (data != -1);

    printf("In-order traversal of the binary search tree: ");
    inOrderTraversal(root);
    printf("\n");

    printf("Enter an element to search for in the binary search tree (or enter -1 to exit): ");
    scanf("%d", &key);

    if (key != -1) {
        struct Node* result = search(root, key);
        if (result) {
            printf("Element %d found in the binary search tree.\n", key);
        } else {
            printf("Element %d not found in the binary search tree.\n", key);
        }
    }

    return 0;
}
