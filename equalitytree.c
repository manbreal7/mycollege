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


int areTreesEqual(struct Node* root1, struct Node* root2) {
    if (root1 == NULL && root2 == NULL) {
        return 1;
    }

    if (root1 != NULL && root2 != NULL) {

        if (root1->data == root2->data) {

            return areTreesEqual(root1->left, root2->left) && areTreesEqual(root1->right, root2->right);
        }
    }

    return 0;
}


struct Node* buildTree(int arr[], int n, int* index) {
    if (*index >= n || arr[*index] == -1) {
        (*index)++;
        return NULL;
    }

    struct Node* root = createNode(arr[(*index)++]);
    root->left = buildTree(arr, n, index);
    root->right = buildTree(arr, n, index);
    return root;
}

int main() {
    int arr1[100], arr2[100];
    int n1, n2;
    int i;

    printf("Enter the elements of the first tree as a space-separated array (-1 for empty nodes):\n");
    n1 = 0;
    i = 0;
    while (1) {
        int data;
        scanf("%d", &data);
        if (data == -1) {
            break;
        }
        arr1[i++] = data;
        n1++;
    }

    printf("Enter the elements of the second tree as a space-separated array (-1 for empty nodes):\n");
    n2 = 0;
    i = 0;
    while (1) {
        int data;
        scanf("%d", &data);
        if (data == -1) {
            break;
        }
        arr2[i++] = data;
        n2++;
    }

    int index1 = 0;
    int index2 = 0;

    struct Node* root1 = buildTree(arr1, n1, &index1);
    struct Node* root2 = buildTree(arr2, n2, &index2);

    if (areTreesEqual(root1, root2)) {
        printf("The two trees are equal.\n");
    } else {
        printf("The two trees are not equal.\n");
    }

    return 0;
}
