//Construct a Binary Tree from the given level-order traversal.
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Construct tree from level order
struct Node* buildTree(int arr[], int n) {
    if (n == 0) return NULL;

    struct Node* root = createNode(arr[0]);

    // Queue for nodes
    struct Node* queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;

    int i = 1;

    while (i < n) {
        struct Node* current = queue[front++];

        // Left child
        if (i < n) {
            current->left = createNode(arr[i++]);
            queue[rear++] = current->left;
        }

        // Right child
        if (i < n) {
            current->right = createNode(arr[i++]);
            queue[rear++] = current->right;
        }
    }

    return root;
}

// Inorder traversal (to verify)
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Main
int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);

    struct Node* root = buildTree(arr, n);

    printf("Inorder Traversal: ");
    inorder(root);

    return 0;
}