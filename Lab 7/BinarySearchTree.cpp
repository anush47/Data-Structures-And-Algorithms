#include <iostream>
using namespace std;

// Define a node struct
struct node {
    int key;
    struct node *left, *right;
};

// Inorder traversal
void traverseInOrder(struct node *root) {
    if (root != NULL) {
        traverseInOrder(root->left);
        cout << root->key << " ";
        traverseInOrder(root->right);
    }
}

// Insert a node
struct node *insertNode(struct node *currNode, int key) {
    if (currNode == NULL) {     // If the current node is NULL, create a new node
        struct node *newNode = new node;
        newNode->key = key;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
    
    // Recursively insert the node in the left or right subtree
    if (key < currNode->key) {
        currNode->left = insertNode(currNode->left, key);
    } 
    else if (key > currNode->key) {
        currNode->right = insertNode(currNode->right, key);
    }

    return currNode;
}

// Deleting a node
struct node *deleteNode(struct node *root, int key) {
    // If the root is NULL, return the root
    if (root == NULL) {
        return root;
    }
    // If the key < root's key, recursively delete from the left 
    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    }  
    // If the key > root's key, recursively delete from the right
    else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    } 
    // If the key is equal to the root's key, delete root
    else {
        // If the root has no left child, replace root with right child
        if (root->left == NULL) {
            struct node *temp = root->right;
            delete root;
            return temp;
        }
        // If the root has no right child, replace root with left child
        else if (root->right == NULL) {
            struct node *temp = root->left;
            delete root;
            return temp;
        }
        // If the root has both left and right children, inorder successor
        struct node *temp = root->right;
        while (temp->left != NULL) {
            temp = temp->left;
        }
        // Replace root key with the inorder successor's
        root->key = temp->key;
        // Recursively delete the inorder successor from right
        root->right = deleteNode(root->right, temp->key);
    }
    // Return the root
    return root;
}

// Driver code
int main() {
    struct node *root = NULL;

    int operation;
    int operand;
    cin >> operation;

    while (operation != -1) {
        switch(operation) {
            case 1: // insert
                cin >> operand;
                root = insertNode(root, operand);
                cin >> operation;
                break;
            case 2: // delete
                cin >> operand;
                root = deleteNode(root, operand);
                cin >> operation;
                break;
            default:
                cout << "Invalid Operator!\n";
                return 0;
        }
    } 
    
    traverseInOrder(root);
}
