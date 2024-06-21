#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node* lc;
    struct Node* rc;
    int data;
};

struct Node* createTree() {
    int val;
    printf("Enter a value (or -1 to break): ");
    scanf("%d", &val);

    if (val == -1) {
        return NULL;
    }

    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    printf("Left child of %d\n", val);
    temp->lc = createTree();
    printf("Right child of %d\n", val);
    temp->rc = createTree();
    return temp;
}

void Inorder(struct Node* node) {
    if (node == NULL) {
        return;
    }
    Inorder(node->lc);
    printf("%d ", node->data);
    Inorder(node->rc);
}

void print(struct Node* root) {
    printf("Inorder Traversal: ");
    Inorder(root);
    printf("\n");
}

int main() {
    struct Node* root = createTree();
    print(root);
    return 0;
}
