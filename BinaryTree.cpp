#include <iostream>
using namespace std;

// Define a Node structure for the binary tree
struct Node {
    int data;          // Data stored in the node
    Node* left;        // Pointer to the left child
    Node* right;       // Pointer to the right child

    // Constructor to initialize a new node
    Node(int value) {
        data = value;
        left = nullptr;  // Initially, no left child
        right = nullptr; // Initially, no right child
    }
};

// Class to represent the binary tree
class BinaryTree {
private:
    Node* root; // Root node of the binary tree

    // Helper function for recursive insertion
    Node* insert(Node* node, int value) {
        if (node == nullptr) {
            // If the current node is null, create a new node
            return new Node(value);
        }

        // If the value is less than the current node's data, insert into the left subtree
        if (value < node->data) {
            node->left = insert(node->left, value);
        }
        // If the value is greater than or equal to the current node's data, insert into the right subtree
        else {
            node->right = insert(node->right, value);
        }

        return node; // Return the updated node
    }

    // Helper function for in-order traversal (left, root, right)
    void inOrderTraversal(Node* node) {
        if (node == nullptr) {
            return; // Base case: if the node is null, return
        }

        inOrderTraversal(node->left);  // Visit the left subtree
        cout << node->data << " ";     // Print the current node's data
        inOrderTraversal(node->right); // Visit the right subtree
    }

    // Helper function for pre-order traversal (root, left, right)
    void preOrderTraversal(Node* node) {
        if (node == nullptr) {
            return; // Base case: if the node is null, return
        }

        cout << node->data << " ";      // Print the current node's data
        preOrderTraversal(node->left);  // Visit the left subtree
        preOrderTraversal(node->right); // Visit the right subtree
    }

    // Helper function for post-order traversal (left, right, root)
    void postOrderTraversal(Node* node) {
        if (node == nullptr) {
            return; // Base case: if the node is null, return
        }

        postOrderTraversal(node->left);  // Visit the left subtree
        postOrderTraversal(node->right); // Visit the right subtree
        cout << node->data << " ";       // Print the current node's data
    }

public:
    // Constructor to initialize the binary tree
    BinaryTree() {
        root = nullptr; // Initially, the tree is empty
    }

    // Function to insert a value into the binary tree
    void insert(int value) {
        root = insert(root, value); // Call the recursive helper function
    }

    // Function to perform in-order traversal
    void inOrder() {
        cout << "In-order Traversal: ";
        inOrderTraversal(root); // Call the recursive helper function
        cout << endl;
    }

    // Function to perform pre-order traversal
    void preOrder() {
        cout << "Pre-order Traversal: ";
        preOrderTraversal(root); // Call the recursive helper function
        cout << endl;
    }

    // Function to perform post-order traversal
    void postOrder() {
        cout << "Post-order Traversal: ";
        postOrderTraversal(root); // Call the recursive helper function
        cout << endl;
    }
};

// Main function to demonstrate the binary tree
int main() {
    BinaryTree tree; // Create an instance of the BinaryTree class

    // Insert values into the binary tree
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    // Perform different types of traversals
    tree.inOrder();   // Output 20 30 40 50 60 70 80
    tree.preOrder();  // Output 50 30 20 40 70 60 80
    tree.postOrder(); // Output 20 40 30 60 80 70 50

    return 0;
}