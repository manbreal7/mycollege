#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* lc;
    struct Node* rc;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->lc = NULL;
    newNode->rc = NULL;
    return newNode;
}

struct Node* createTree() {
    int val;
    printf("Enter the value (or -1 to break): ");
    scanf("%d", &val);
    if (val == -1) {
        return NULL;
    }

    struct Node* root = createNode(val);
    printf("Left child of %d\n", val);
    root->lc = createTree();
    printf("Right child of %d\n", val);
    root->rc = createTree();

    return root;
}

void postOrder(struct Node* node) {
    if (node == NULL)
        return;
    postOrder(node->lc);
    postOrder(node->rc);
    printf("%d ", node->data);
}

struct Node* copyTree(struct Node* src) {
    if (!src) {
        return NULL;
    }

    struct Node* newTree = createNode(src->data);
    newTree->lc = copyTree(src->lc);
    newTree->rc = copyTree(src->rc);

    return newTree;
}

int main() {
    struct Node* root1 = createTree();
    printf("Postorder Traversal (Tree 1): ");
    postOrder(root1);
    printf("\n");

    struct Node* root2 = copyTree(root1);

    printf("Postorder Traversal (Tree 2 - Copied from Tree 1): ");
    postOrder(root2);
    printf("\n");

    return 0;
}
