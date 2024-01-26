#include <iostream> // for using cin, cout functions
#include <cstdlib> // Header file required for the exit function

using namespace std; // Enables the use of the std namespace, providing access to C++ standard library components like cout and cin.

// Node class
class Node {
public: // attributes
    int data; // Data stored in the node
    Node* left; // Pointer to the left child node
    Node* right; // Pointer to the right child node


  Node(int data){   // Constructor for the Node class
  this->data=data; // Initialize the value in the node
  this->left=nullptr; // Initialize the left child pointer
  this->right=nullptr; // Initialize the right child pointer
  }

};

// Node2 class
class Node2 {
public: // attributes
    Node* data; // Pointer to a Node object
    Node2* next;// Pointer to the next Node2 object in the linked list

// Constructor for the Node2 class
  Node2(Node* data){
  this->data=data;  // Initialize the pointer to a Node object
  this->next=nullptr; // Initialize the pointer to the next Node2 object
  }

};

// Queue class
class Queue {
private: // attributes
    Node2* front; // Pointer to the front of the queue
    Node2* rear;  // Pointer to the rear of the queue
    int size; // Number of elements in the queue

public: // attributes
// Constructor for the Queue class
    Queue(){
    this->front = nullptr; // Initialize the front pointer
    this->rear = nullptr; // Initialize the rear pointer
    this->size = 0; // Initialize the size to zero
    }
// Check if the queue is empty.
    bool isEmpty() const { // This const member function is designed for read-only access and does not modify the state of the class.
        return front == nullptr; // Returns true if the front pointer is null, indicating an empty queue; otherwise, returns false.
    }

// This function removes elements from the front of the queue (dequeues them).
     void dequeue() {
        if (isEmpty()) { // If the queue is empty
            cout << "Unable to dequeue. The queue is empty!\n"; // If the queue is empty, print an error message.
            return; //exit
        }

        Node2* temp = front;  // Temporary pointer to point to the front element.
        front = front->next; // Move the front element to the next one.
        delete temp; // Delete the previous front element.

        if (front == nullptr) { // If there are no elements in the front anymore
            rear = nullptr;  // If there are no elements in the front anymore, set the rear element to null.
        }

        size--; // Decrease the number of elements in the queue.
    }

// Add a new node with the given item to the rear of the queue.
    void enqueue(Node* item) {
        Node2* newNode = new Node2(item); // Create a new Node2 object using the provided Node item.
 // Check if the queue is empty.
        if (isEmpty()) { // If the queue is empty
            front = rear = newNode; // If the queue is empty, set both front and rear to the new node.
        }
        else { // If the queue is not empty
            rear->next = newNode; // Connect the new node to the current rear.
            rear = newNode; // Update the rear to the new node.
        }

        size++; // Increase the number of elements in the queue.
    }


// This function is marked as const, indicating that it does not modify the state of the class.
    Node* getFrontElement() const { // It is designed for read-only access and does not change any data members of the class.
// Check if the queue is empty.
        if (isEmpty()) { // If the queue is empty
          cout << "Queue is empty. Queue do not have front element.\n"; // If the queue is empty, print an error message.
            exit(EXIT_FAILURE);  // Exit the program with an error message if the queue is empty.
        }
        else{ // If the queue is not empty
        return front->data; // If the queue is not empty, return the data of the front element.
        }
    }


// This function returns the number of elements in the queue.
    int getSize() const {
        return size; // Returns the current size of the queue.
    }

// This function prints the elements of the queue.
    void printElements() const { // This const member function is designed for read-only access and does not modify the state of the class.
// Check if the queue is empty.
        if (isEmpty()) { // If the queue is empty
            cout << "Queue has no elements!\n"; // If the queue is empty, print an message.
            return; //exit
        }

        Node2* temp = front; // Create a temporary pointer to traverse the queue.

        while (temp != nullptr) {  // Traverse the queue and print each element.
           cout << temp->data->data << " "; // Print the data of the current node.
            temp = temp->next; // Move to the next node.
        }

    }
};

//Class Binary Search Tree
class BST {
private: // attributes
    Node* root;  // Pointer to the root node of the binary search tree
    Queue Node3; // Queue object associated with the binary search tree

    // Function to perform in-order traversal of the binary search tree
    void inOrder(Node* node) {
        if (node != nullptr) {
            inOrder(node->left);     // Recursively traverse the left subtree
            cout << node->data << " "; // Print the value of the current node
            inOrder(node->right);    // Recursively traverse the right subtree
        }
    }

public: // attributes
    BST() {  // Constructor for initializing the binary search tree with an empty root
        root = nullptr; // Initialize the root pointer to nullptr as the tree is initially empty
    }

    // Function to insert a new value into the binary search tree
    void insert(int value) {
        Node* newNode = new Node(value); // Create a new node with the given value

        if (root == nullptr) {  // If the tree is empty
            root = newNode; // If the tree is empty, set the new node as the root
            return; //exit
        }

        Node* temp = root; // Traverse the tree to find the appropriate position for the new value

        while (true) {
            // If the new value is less than the current node's value, move to the left subtree
            if (value < temp->data) {
                // If the left child is null, insert the new node here
                if (temp->left == nullptr) {
                    temp->left = newNode;
                    break;
                }
                else {  // Otherwise, continue traversing the left subtree
                    temp = temp->left;
                }
            }
            // If the new value is greater than the current node's value, move to the right subtree
            else if (value > temp->data) {
                // If the right child is null, insert the new node here
                if (temp->right == nullptr) {
                    temp->right = newNode;
                    break;
                }
                else { // Otherwise, continue traversing the right subtree
                    temp = temp->right;
                }
            }
        }
    }

    // Function to perform level order traversal of the binary search tree
    void levelOrder() {
        Node3.enqueue(root); // Enqueue the root node to start the level order traversal

        // Check if the tree is empty
        if (root == nullptr) { // If the tree is empty
            return; //exit
        }

        while (!Node3.isEmpty()) { // Continue traversal while the queue is not empty
            int levelSize = Node3.getSize(); // Get the number of nodes at the current level
            // Process each node at the current level
            for (int i = 0; i < levelSize; i++) {
                // Dequeue the front node from the queue
                Node* temp2 = Node3.getFrontElement();
                Node3.dequeue();

                cout << temp2->data << " "; // Print the value of the dequeued node
                // Enqueue the left child if it exists
                if (temp2->left != nullptr) {
                    Node3.enqueue(temp2->left);
                }
                // Enqueue the right child if it exists
                if (temp2->right != nullptr) {
                    Node3.enqueue(temp2->right);
                }
            }
        }
    }

    // Public method to initiate in-order traversal
    void inOrderTraversal() {
        inOrder(root); // Start in-order traversal from the root
    }
};

// Main function where the program execution starts
int main() {
    BST bst; // Create an instance of the Binary Search Tree (BST)

    // Insert values into the BST
    bst.insert(63);
    bst.insert(61);
    bst.insert(5);
    bst.insert(62);
    bst.insert(89);
    bst.insert(107);

    cout << "Level Order Print:\n"; // Print a message
    bst.levelOrder(); // Perform level order traversal and print the nodes

    cout << "\nIn Order Print:\n"; // Print a message
    bst.inOrderTraversal(); // Perform in-order traversal and print the nodes

    return 0; // Return 0 to indicate successful program execution
}
