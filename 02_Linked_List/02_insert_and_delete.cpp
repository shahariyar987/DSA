#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void display(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "NULL\n";
}

void insertAtBeginning(Node*& head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

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

void deleteFromBeginning(Node*& head) {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;
    head = head->next;
    delete temp;
}

void deleteFromEnd(Node*& head) {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }

    Node* current = head;
    while (current->next->next != nullptr) current = current->next;

    delete current->next;
    current->next = nullptr;
}

int main() {
    Node* head = nullptr;
    int choice, value;

    do {
        cout << "\n===== Linked List =====\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Delete from beginning\n";
        cout << "4. Delete from end\n";
        cout << "5. Display\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                insertAtBeginning(head, value);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> value;
                insertAtEnd(head, value);
                break;
            case 3:
                deleteFromBeginning(head);
                break;
            case 4:
                deleteFromEnd(head);
                break;
            case 5:
                display(head);
                break;
            case 6:
                cout << "Program terminated.\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 6);

    return 0;
}
