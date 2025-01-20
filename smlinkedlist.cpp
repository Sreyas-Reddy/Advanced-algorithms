#include <iostream>
using namespace std;

// Node structure for the linked list
struct Node {
    int row;    
    int col;    
    int value;  
    Node* next; 

    // Constructor to initialize a node
    Node(int r, int c, int v) : row(r), col(c), value(v), next(nullptr) {}
};

// Class to represent the sparse matrix
class SparseMatrix {
private:
    Node* head; // Head pointer of the linked list
    int rows, cols; // Dimensions of the matrix

public:
    // Constructor
    SparseMatrix(int r, int c) : head(nullptr), rows(r), cols(c) {}

    // Function to add a non-zero element to the sparse matrix
    void addElement(int r, int c, int v) {
        if (v == 0) return; // Skip zero values
        Node* newNode = new Node(r, c, v);

        if (!head) {
            // If the list is empty, set the new node as the head
            head = newNode;
        } else {
            // Insert the new node at the end of the linked list
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Function to display the sparse matrix representation
    void displaySparse() {
        cout << "Sparse Matrix Representation:" << endl;
        Node* temp = head;
        while (temp) {
            cout << "Row: " << temp->row << ", Col: " << temp->col << ", Value: " << temp->value << endl;
            temp = temp->next;
        }
    }

    // Function to display the full matrix
    void displayFullMatrix() {
        cout << "Full Matrix Representation:" << endl;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                bool found = false;
                Node* temp = head;
                while (temp) {
                    if (temp->row == i && temp->col == j) {
                        cout << temp->value << " ";
                        found = true;
                        break;
                    }
                    temp = temp->next;
                }
                if (!found) {
                    cout << "0 ";
                }
            }
            cout << endl;
        }
    }

    // Destructor to free memory
    ~SparseMatrix() {
        Node* temp;
        while (head) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    SparseMatrix sm(4, 5);

    // Adding non-zero elements
    sm.addElement(0, 1, 5);
    sm.addElement(1, 3, 8);
    sm.addElement(3, 0, 6);

    // Display sparse matrix
    sm.displaySparse();

    // Display full matrix
    sm.displayFullMatrix();

    return 0;
}