#include <iostream>
using namespace std;



// structure for node
struct Node {
    int data;   
    Node* next;
};

// linked list class
class Linkedlist{
    Node* head;                     // pointer to the head of the list

public:
    Linkedlist() : head(NULL){}     // constructor for head to NULL

    void InsertAtStart(int val){    // function to insert a new node at the start of the list
        Node* newNode = new Node(); 
        newNode->data = val;      
        newNode->next = head;      
        head = newNode;   
    }


    void InsetAtEnd(int val){
        Node* newNode = new Node(); 
        newNode->data = val;       
        newNode->next = NULL;       

        // If the list is empty, update the head to the new node
        if (!head) {
            head = newNode;
            return;
        }

        // Traverse to the last node
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }

        // Update the last node's next to the new node
        temp->next = newNode;
    }

        // function to add new node at a certain position in the list
    void insertAtPosition(int val, int position) {
        if (position < 1) {
            cout << "Position should be >= 1." << endl;
            return;
        }

        if (position == 1) {
            InsertAtStart(val);
            return;
        }

        Node* newNode = new Node(); 
        newNode->data = val;     

        // Traverse to the node before the desired position
        Node* temp = head;
        for (int i = 1; i < position - 1 && temp; ++i) {
            temp = temp->next;
        }

        // If the position is out of range, print an error message
        if (!temp) {
            cout << "Position out of range." << endl;
            delete newNode;
            return;
        }

        // Insert the new node at the desired position
        newNode->next = temp->next;
        temp->next = newNode;
    }


    // function to delete the first node from the start of list
    void deleteFromBeginning() {
        if (!head) {
            cout << "List is empty." << endl; // if nothing in the list
            return;
        }

        Node* temp = head; 
        head = head->next; 
        delete temp;      
    }

    // fucntion to delete from the end of the list
    void deleteFromEnd() {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }

        if (!head->next) {
            delete head;   
            head = NULL;   
            return;
        }

        // traverse to the second to last node
        Node* temp = head;
        while (temp->next->next) {
            temp = temp->next;
        }
        
        //  Delete the last node
        delete temp->next; 
        // Set the second-to-last node's next to NULL
        temp->next = NULL; 
    }


    // delete a node from a certain position in the list
    void deleteFromPosition(int position) {
        if (position < 1) {
            cout << "Position should be >= 1." << endl;
            return;
        }

        if (position == 1) {
            deleteFromBeginning();
            return;
        }

        Node* temp = head;
        for (int i = 1; i < position - 1 && temp; ++i) {
            temp = temp->next;
        }

        if (!temp || !temp->next) {
            cout << "Position out of range." << endl;
            return;
        }
        // Save the node to be deleted
        Node* nodeToDelete = temp->next; 
        // Update the next pointer
        temp->next = temp->next->next;   
         // Delete the node
        delete nodeToDelete;            
    }

    // Function to print the nodes of  the linked list
    void show() {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> "; 
            temp = temp->next;
        }
        cout << "NULL" << endl; 
    }
};


int main() {
    // Initialize a new linked list
    Linkedlist list1;

    // Insert elements at the end
    list1.InsetAtEnd(9);
    list1.InsetAtEnd(17);

    // Insert element at the beginning
    list1.InsertAtStart(4);

    // Insert element at a specific position
    list1.insertAtPosition(6, 9);

    cout << "Linked list after insertions: ";
    list1.show();

    // Delete element from the beginning
    list1.deleteFromBeginning();
    cout << "Linked list after deleting from beginning: ";
    list1.show();

    // Delete element from the end
    list1.deleteFromEnd();
    cout << "Linked list after deleting from end: ";
    list1.show();

    // Delete element from a specific position
    list1.deleteFromPosition(5);
    cout << "Linked list after deleting from position 5: ";
    list1.show();

    return 0;
}
