#include <iostream>
using namespace std;

// Node structure for storing non-zero elements
struct Node {
    int row, col, value;
    Node* next;
    Node(int r, int c, int v) : row(r), col(c), value(v), next(nullptr) {}
};

// SparseMatrix using a linked list
class SparseMatrix {
private:
    int rows, cols;
    Node* head;

public:
    SparseMatrix(int r, int c) : rows(r), cols(c), head(nullptr) {}

    void insert(int r, int c, int v) {
        if (v == 0) return;
        Node* newNode = new Node(r, c, v);
        if (!head) {            // first node
            head = newNode;
            return;
        }
        Node* temp = head;      // append to tail
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }

    void display() {
        cout << "Sparse Matrix (Linked List Form):\n";
        Node* temp = head;
        while (temp) {
            cout << "(" << temp->row << "," << temp->col << ") -> " << temp->value << endl;
            temp = temp->next;
        }
    }

    int countNonZero() {
        int count = 0;
        Node* temp = head;
        while (temp) {
            count++;
            temp = temp->next;
        }
        return count;
    }
};

int main() {
    // Example dense 4x4 matrix
    int dense[4][4] = {
        {0, 0, 3, 0},
        {22, 0, 0, 0},
        {0, 17, 0, 9},
        {0, 0, 0, 5}
    };

    SparseMatrix sm(4, 4);

    // Convert dense to sparse (linked list)
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (dense[i][j] != 0) {
                sm.insert(i, j, dense[i][j]);
            }
        }
    }

    sm.display();
    cout << "Total non-zero elements: " << sm.countNonZero() << endl;

    return 0;
}
