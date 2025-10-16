#include <stdio.h>
#include <stdlib.h>

// Define structure for a binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert nodes in level order (automated tree creation)
struct Node* insertLevelOrder(int arr[], int i, int n) {
    if (i < n) {
        struct Node* root = createNode(arr[i]);
        root->left = insertLevelOrder(arr, 2 * i + 1, n);
        root->right = insertLevelOrder(arr, 2 * i + 2, n);
        return root;
    }
    return NULL;
}

// Calculate height of the tree
int height(struct Node* root) {
    if (root == NULL)
        return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    return (lh > rh ? lh : rh) + 1;
}

// Get width of a given level
int getWidth(struct Node* root, int level) {
    if (root == NULL)
        return 0;
    if (level == 1)
        return 1;
    return getWidth(root->left, level - 1) + getWidth(root->right, level - 1);
}

// Get maximum width of the tree
int getMaxWidth(struct Node* root) {
    int maxWidth = 0;
    int h = height(root);
    for (int i = 1; i <= h; i++) {
        int width = getWidth(root, i);
        if (width > maxWidth)
            maxWidth = width;
    }
    return maxWidth;
}

// Tree Traversals
void preorder(struct Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void postorder(struct Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Create binary tree automatically from array
    struct Node* root = insertLevelOrder(arr, 0, n);

    printf("Preorder: ");
    preorder(root);
    printf("\nInorder: ");
    inorder(root);
    printf("\nPostorder: ");
    postorder(root);

    int width = getMaxWidth(root);
    printf("\n\nMaximum Width of Tree: %d\n", width);

    return 0;
}