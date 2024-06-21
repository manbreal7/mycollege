#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct QueueNode {
    struct Node* data;
    struct QueueNode* next;
};

struct Queue {
    struct QueueNode* front;
    struct QueueNode* rear;
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

struct QueueNode* createQueueNode(struct Node* data) {
    struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

void enqueue(struct Queue* queue, struct Node* data) {
    struct QueueNode* newNode = createQueueNode(data);
    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
        return;
    }
    queue->rear->next = newNode;
    queue->rear = newNode;
}

struct Node* dequeue(struct Queue* queue) {
    if (queue->front == NULL) {
        return NULL;
    }
    struct QueueNode* temp = queue->front;
    struct Node* data = temp->data;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(temp);
    return data;
}

void levelOrderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }

    struct Queue* queue = createQueue();
    enqueue(queue, root);

    while (queue->front != NULL) {
        struct Node* current = dequeue(queue);
        printf("%d ", current->data);

        if (current->left != NULL) {
            enqueue(queue, current->left);
        }

        if (current->right != NULL) {
            enqueue(queue, current->right);
        }
    }
}

int main() {
    struct Node* root = NULL;
    int data;

    do {
        printf("enter data (-1 to exit): ");
        scanf("%d", &data);

        if (data != -1) {
            root = insert(root, data);
        }
    } while (data != -1);

    printf("Level order traversal of the binary search tree: ");
    levelOrderTraversal(root);

    return 0;
}
