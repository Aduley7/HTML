#include <stdio.h>
#include <stdlib.h>

// Structure for a node of the tree
struct Node {
    int data;
    struct Node *left, *right;
};

// Function to create a new node with given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a new node into the BST
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    
    // Recursively insert the data in the correct place
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

// Function to find the minimum value node in the tree
struct Node* findMin(struct Node* root) {
    while (root && root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Function to delete a node from the BST
struct Node* deleteNode(struct Node* root, int data) {
    if (root == NULL) {
        return root;
    }

    // Find the node to delete
    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        // Node with one child or no child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        struct Node* temp = findMin(root->right);

        // Copy the inorder successor's content to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

// Function to perform inorder traversal of the tree (LNR)
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Function to display the tree in a simple way
void display(struct Node* root) {
    if (root == NULL) {
        printf("Tree is empty\n");
        return;
    }

    printf("Inorder Traversal: ");
    inorder(root);
    printf("\n");
}

int main() {
    struct Node* root;

    // Inserting values into the tree
    root = createNode();
    // Display the tree
    printf("BST after insertion:\n");
    display(root);

    // Deleting nodes
    printf("\nDeleting 20\n");
    root = deleteNode(root);
    display(root);

    printf("\nDeleting 30\n");
    root = deleteNode(root);
    display(root);

    printf("\nDeleting 50\n");
    root = deleteNode(root);
    display(root);

    return 0;
}