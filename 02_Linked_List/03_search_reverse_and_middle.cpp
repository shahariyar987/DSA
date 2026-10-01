#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insertAtEnd(Node*& head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* current = head;
    while (current->next != nullptr) current = current->next;
    current->next = newNode;
}

void display(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "NULL\n";
}

void search(Node* head, int value) {
    Node* current = head;
    int position = 0;

    while (current != nullptr) {
        if (current->data == value) {
            cout << "Value found at position " << position + 1 << endl;
            return;
        }
        current = current->next;
        position++;
    }

    cout << "Value not found.\n";
}

void reverseList(Node*& head) {
    Node* previous = nullptr;
    Node* current = head;

    while (current != nullptr) {
        Node* nextNode = current->next;
        current->next = previous;
        previous = current;
        current = nextNode;
    }

    head = previous;
}

void findMiddle(Node* head) {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    cout << "Middle element = " << slow->data << endl;
}

int main() {
    Node* head = nullptr;
    int n;

    cout << "Enter number of nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int value;
        cout << "Enter value: ";
        cin >> value;
        insertAtEnd(head, value);
    }

    cout << "\nOriginal List: ";
    display(head);

    int searchValue;
    cout << "\nEnter value to search: ";
    cin >> searchValue;

    search(head, searchValue);
    findMiddle(head);

    reverseList(head);

    cout << "\nReversed List: ";
    display(head);

    return 0;
}
