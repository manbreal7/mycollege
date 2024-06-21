#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node* lc;
    struct Node* rc;
    int data;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->lc = NULL;
    newNode->rc = NULL;
    return newNode;
}

struct Node* insertLevelOrder(int arr[], struct Node* root, int i, int n) {
    if (i < n) {
        struct Node* temp = createNode(arr[i]);
        root = temp;

        root->lc = insertLevelOrder(arr, root->lc, 2 * i + 1, n);
        root->rc = insertLevelOrder(arr, root->rc, 2 * i + 2, n);
    }
    return root;
}

int isMirror(struct Node* a, struct Node* b) {
    if (!a && !b) {
        return 1;
    }
    if (!a || !b) {
        return 0;  
    }
    return a->data == b->data && isMirror(a->lc, b->rc) && isMirror(a->rc, b->lc);
}

int areTreesMirror(int arr1[], int arr2[], int n) {
    struct Node* root1 = NULL;
    struct Node* root2 = NULL;

    root1 = insertLevelOrder(arr1, root1, 0, n);
    root2 = insertLevelOrder(arr2, root2, 0, n);

    return isMirror(root1, root2);
}

int main() {
    int n;
    printf("Enter the number of elements in each tree: ");
    scanf("%d", &n);

    int arr1[n];
    int arr2[n];

    printf("Enter elements for the first tree:\n");
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr1[i]);
    }

    printf("Enter elements for the second tree:\n");
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr2[i]);
    }

    if (areTreesMirror(arr1, arr2, n)) {
        printf("mirror images\n");
    } else {
        printf("not mirror images\n");
    }

    return 0;
}
