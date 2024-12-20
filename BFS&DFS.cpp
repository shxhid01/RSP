#include <iostream>
#include <queue>  // For BFS
#include <stack>  // For iterative DFS
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

    // Helper function for recursive DFS (in-order traversal)
    void dfsRecursive(Node* node) {
        if (node == nullptr) {
            return; // Base case: if the node is null, return
        }

        // Visit the left subtree
        dfsRecursive(node->left);

        // Visit the current node
        cout << node->data << " ";

        // Visit the right subtree
        dfsRecursive(node->right);
    }

public:
    // Constructor to initialize the binary tree
    BinaryTree() {
        root = nullptr; // Initially, the tree is empty
    }

    // Function to insert a value into the binary tree
    void insert(int value) {
        root = insertHelper(root, value);
    }

    // Helper function for insertion
    Node* insertHelper(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value); // Create a new node if the current node is null
        }

        if (value < node->data) {
            node->left = insertHelper(node->left, value); // Insert into the left subtree
        } else {
            node->right = insertHelper(node->right, value); // Insert into the right subtree
        }

        return node; // Return the updated node
    }

    // Function to perform DFS (recursive)
    void dfs() {
        cout << "DFS (Recursive - In-order Traversal): ";
        dfsRecursive(root); // Call the recursive helper function
        cout << endl;
    }

    // Function to perform DFS (iterative using a stack)
    void dfsIterative() {
        if (root == nullptr) {
            cout << "Tree is empty!" << endl;
            return;
        }

        cout << "DFS (Iterative): ";
        stack<Node*> s; // Stack to store nodes
        s.push(root);   // Start with the root node

        while (!s.empty()) {
            Node* current = s.top(); // Get the top node
            s.pop();                 // Remove it from the stack

            // Visit the current node
            cout << current->data << " ";

            // Push the right child first (so the left child is processed first)
            if (current->right) {
                s.push(current->right);
            }

            // Push the left child
            if (current->left) {
                s.push(current->left);
            }
        }
        cout << endl;
    }

    // Function to perform BFS (iterative using a queue)
    void bfs() {
        if (root == nullptr) {
            cout << "Tree is empty!" << endl;
            return;
        }

        cout << "BFS (Level-order Traversal): ";
        queue<Node*> q; // Queue to store nodes
        q.push(root);   // Start with the root node

        while (!q.empty()) {
            Node* current = q.front(); // Get the front node
            q.pop();                   // Remove it from the queue

            // Visit the current node
            cout << current->data << " ";

            // Enqueue the left child
            if (current->left) {
                q.push(current->left);
            }

            // Enqueue the right child
            if (current->right) {
                q.push(current->right);
            }
        }
        cout << endl;
    }
};

// Main function to demonstrate DFS and BFS
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

    // Perform DFS (recursive and iterative)
    tree.dfs();          // Output 20 30 40 50 60 70 80 (in-order traversal)
    tree.dfsIterative(); // Output 50 30 20 40 70 60 80 (pre-order traversal)

    // Perform BFS
    tree.bfs();          // Output 50 30 70 20 40 60 80 (level-order traversal)

    return 0;
}