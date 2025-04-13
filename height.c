#include <stdio.h>
#include <stdlib.h>

// Structure for a node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Count leaf nodes
int countLeafNodes(struct Node* root) {
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

// Find maximum value
int findMax(struct Node* root) {
    while (root != NULL && root->right != NULL)
    {
        root = root->right;
    }
    printf("\nLargest value is %d", root->data);
}

// Find minimum value
int findMin(struct Node* root) {
    while(root != NULL && root->left != NULL)
    {
        root = root->left;
    }
    printf("\nSmallest value is %d\n", root->data);
}

// Calculate height of tree
int findHeight(struct Node* root) {
    if (root == NULL)
        return -1; // Height of empty tree is -1
    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight);
}


int main() {
    int choice;

    
    struct Node* root = createNode(11);
    root->left = createNode(5);
    root->right = createNode(21);
    root->left->left = createNode(8);
    root->left->right = createNode(7);
    root->right->right = createNode(371);

    do {
        printf("1. Count Leaf Nodes\n");
        printf("2. Find Maximum Value\n");
        printf("3. Find Minimum Value\n");
        printf("4. Find Height of Tree\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Number of Leaf Nodes: %d\n", countLeafNodes(root));
                break;
            case 2:
                printf("Maximum Value: %d\n", findMax(root));
                break;
            case 3:
                printf("Minimum Value: %d\n", findMin(root));
                break;
            case 4:
                printf("Height of Tree: %d\n", findHeight(root));
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 5);

    return 0;
}
