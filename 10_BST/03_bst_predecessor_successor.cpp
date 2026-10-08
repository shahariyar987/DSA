#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

Node* insert(Node* root, int value) {
    if (root == nullptr)
        return new Node(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

void findPredecessorSuccessor(
    Node* root,
    int key,
    Node*& predecessor,
    Node*& successor
) {
    Node* current = root;

    while (current != nullptr) {
        if (current->data == key) {
            if (current->left != nullptr) {
                Node* temp = current->left;

                while (temp->right != nullptr)
                    temp = temp->right;

                predecessor = temp;
            }

            if (current->right != nullptr) {
                Node* temp = current->right;

                while (temp->left != nullptr)
                    temp = temp->left;

                successor = temp;
            }

            break;
        }

        if (key < current->data) {
            successor = current;
            current = current->left;
        } else {
            predecessor = current;
            current = current->right;
        }
    }
}

int main() {
    Node* root = nullptr;
    int n;

    cout << "Enter number of values: ";
    cin >> n;

    cout << "Enter values:\n";

    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        root = insert(root, value);
    }

    int key;
    cout << "Enter key: ";
    cin >> key;

    Node* predecessor = nullptr;
    Node* successor = nullptr;

    findPredecessorSuccessor(
        root,
        key,
        predecessor,
        successor
    );

    if (predecessor != nullptr)
        cout << "Predecessor = " << predecessor->data << endl;
    else
        cout << "Predecessor does not exist.\n";

    if (successor != nullptr)
        cout << "Successor = " << successor->data << endl;
    else
        cout << "Successor does not exist.\n";

    return 0;
}
