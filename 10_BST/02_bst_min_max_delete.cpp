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

Node* findMinimum(Node* root) {
    Node* current = root;

    while (current != nullptr && current->left != nullptr)
        current = current->left;

    return current;
}

Node* findMaximum(Node* root) {
    Node* current = root;

    while (current != nullptr && current->right != nullptr)
        current = current->right;

    return current;
}

Node* deleteNode(Node* root, int value) {
    if (root == nullptr)
        return nullptr;

    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    } else {
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }

        if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* temp = findMinimum(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

void inorder(Node* root) {
    if (root == nullptr)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
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

    if (root == nullptr) {
        cout << "BST is empty.\n";
        return 0;
    }

    Node* minimum = findMinimum(root);
    Node* maximum = findMaximum(root);

    cout << "\nMinimum = " << minimum->data << endl;
    cout << "Maximum = " << maximum->data << endl;

    int value;
    cout << "\nEnter value to delete: ";
    cin >> value;

    root = deleteNode(root, value);

    cout << "BST after deletion: ";
    inorder(root);
    cout << endl;

    return 0;
}
