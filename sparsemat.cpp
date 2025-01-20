#include <iostream>
#include <vector>
using namespace std;

// Structure to represent a sparse matrix element
struct Element {
    int row;    // Row index
    int col;    // Column index
    int value;  // Non-zero value
};

class SparseMatrix {
private:
    int rows, cols;              // Dimensions of the matrix
    vector<Element> elements;    // Vector to store non-zero elements

public:
    // Constructor to initialize the sparse matrix
    SparseMatrix(int r, int c) : rows(r), cols(c) {}

    // Function to add a non-zero element
    void addElement(int r, int c, int val) {
        if (val != 0) {
            elements.push_back({r, c, val});
        }
    }

    // Function to display the sparse matrix
    void display() {
        cout << "Sparse Matrix Representation:" << endl;
        for (const auto &elem : elements) {
            cout << "Row: " << elem.row << ", Col: " << elem.col
                 << ", Value: " << elem.value << endl;
        }
    }

    // Function to convert to a full matrix and display it
    void displayFullMatrix() {
        cout << "Full Matrix Representation:" << endl;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                bool found = false;
                for (const auto &elem : elements) {
                    if (elem.row == i && elem.col == j) {
                        cout << elem.value << " ";
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "0 ";
                }
            }
            cout << endl;
        }
    }
};

int main() {
    // Example: Sparse Matrix of 4x5 dimensions
    SparseMatrix sm(4, 5);

    // Adding non-zero elements
    sm.addElement(0, 1, 5);
    sm.addElement(1, 3, 8);
    sm.addElement(3, 0, 6);

    // Display sparse matrix
    sm.display();

    // Display full matrix
    sm.displayFullMatrix();

    return 0;
}