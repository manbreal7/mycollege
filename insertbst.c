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


void inOrderTraversal(struct Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int data, choice;

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

    return 0;
}
