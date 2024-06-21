#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* lc;
    struct Node* rc;
};

struct Node* createNode(int val) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->lc = NULL;
    temp->rc = NULL;
    return temp;
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

void preOrder(struct Node* node) {
    if (node == NULL)
        return;
    printf("%d ", node->data);
    preOrder(node->lc);
    preOrder(node->rc);
}

void inOrder(struct Node* node) {
    if (node == NULL)
        return;
    inOrder(node->lc);
    printf("%d ", node->data);
    inOrder(node->rc);
}

void levelOrder(struct Node* root) {
    if (root == NULL)
        return;
    printf("Level order traversal: ");
    struct Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        struct Node* current = queue[front++];
        printf("%d ", current->data);

        if (current->lc != NULL) {
            queue[rear++] = current->lc;
        }

        if (current->rc != NULL) {
            queue[rear++] = current->rc;
        }
    }
    printf("\n");
}

void iterativePreorder(struct Node* root) {
    printf("Iterative Preorder Traversal: ");
    if (root == NULL)
        return;

    struct Node* stack[100];
    int top = -1;
    struct Node* current = root;

    stack[++top] = current;
    while (top >= 0) {
        current = stack[top--];
        printf("%d ", current->data);

        if (current->rc != NULL) {
            stack[++top] = current->rc;
        }

        if (current->lc != NULL) {
            stack[++top] = current->lc;
        }
    }
    printf("\n");
}

void iterativeInorder(struct Node* root) {
    printf("Iterative Inorder Traversal: ");
    if (root == NULL)
        return;

    struct Node* stack[100];
    int top = -1;
    struct Node* current = root;

    while (current != NULL || top != -1) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->lc;
        }

        current = stack[top--];
        printf("%d ", current->data);
        current = current->rc;
    }
    printf("\n");
}

void iterativePostorder(struct Node* root) {
    printf("Iterative Postorder Traversal: ");
    if (root == NULL)
        return;

    struct Node* stack1[100];
    struct Node* stack2[100];
    int top1 = -1;
    int top2 = -1;

    stack1[++top1] = root;

    while (top1 != -1) {
        struct Node* current = stack1[top1--];
        stack2[++top2] = current;

        if (current->lc != NULL) {
            stack1[++top1] = current->lc;
        }

        if (current->rc != NULL) {
            stack1[++top1] = current->rc;
        }
    }

    while (top2 != -1) {
        printf("%d ", stack2[top2--]->data);
    }

    printf("\n");
}

bool searchParent(struct Node* curr, int elem) {
    if (curr == NULL) {
        return false;
    }

    if (curr->lc) {
        if (curr->lc->data == elem) {
            printf("Parent is %d\n", curr->data);
            return true;
        } else if(searchParent(curr->lc, elem))
        {
            return true;
        }
    }

    if (curr->rc) {
        if (curr->rc->data == elem) {
            printf("Parent is %d\n", curr->data);
            return true;
        } else if(searchParent(curr->rc, elem)){
            return true;
        }
    }

    return false;
}

void parent(struct Node* root, int elem) {
    if (root == NULL) {
        printf("The tree is empty.\n");
    } else if (root->data == elem) {
        printf("Root has no parent.\n");
    } else {
        bool parentFound = searchParent(root, elem);
        if(!parentFound)
        {
            printf("Element does not exist in the tree.\n");
        }
}
}


int counter(struct Node* node) {
    if (node == NULL)
        return 0;
    int lDepth = counter(node->lc);
    int rDepth = counter(node->rc);

    if (lDepth > rDepth)
        return (lDepth + 1);
    else
        return (rDepth + 1);
}

void level(struct Node* root) {
    int v = counter(root);
    printf("Total Depth is: %d\n", v);
}

bool searchAncestor(struct Node* node, int elem) {
    if (node == NULL)
        return false;
    if (node->data == elem)
        return true;
    if (searchAncestor(node->lc, elem) || searchAncestor(node->rc, elem)) {
        printf("%d ", node->data);
        return true;
    }
    return false;
}

void ancestors(struct Node* root, int elem) {
    if (root == NULL) {
        printf("The tree is empty.\n");
    } else if (root->data == elem) {
        printf("Root element has no ancestor.\n");
    } else {
        if (!searchAncestor(root, elem)) {
            printf("Element does not exist in the tree.\n");
        }
    }
}

int leafCount(struct Node* node) {
    if (node == NULL)
        return 0;
    if (node->lc == NULL && node->rc == NULL)
        return 1;
    return leafCount(node->lc) + leafCount(node->rc);
}

void leafs(struct Node* root) {
    printf("\nLeafs present by leafcount: %d\n", leafCount(root));
}

int main() {
    struct Node* root = createTree();

    iterativeInorder(root);
    iterativePostorder(root);
    iterativePreorder(root);

    int n;
    printf("Find parent of? ");
    scanf("%d", &n);
    parent(root, n);
    level(root);
    printf("Find ancestor of? ");
    scanf("%d", &n);
    ancestors(root, n);
    leafs(root);

    return 0;
}
