#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    Node* head = nullptr;
    Node* tail = nullptr;

    for (int i = 0; i < n; i++) {
        int value;
        cout << "Enter value " << i + 1 << ": ";
        cin >> value;

        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    cout << "\nLinked List: ";
    Node* current = head;

    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->next;
    }

    cout << "NULL\n";
    return 0;
}
