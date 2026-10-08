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

int countNodes(Node* root) {
    if (root == nullptr)
        return 0;

    return 1 + countNodes(root->left) + countNodes(root->right);
}

int countLeafNodes(Node* root) {
    if (root == nullptr)
        return 0;

    if (root->left == nullptr && root->right == nullptr)
        return 1;

    return countLeafNodes(root->left) +
           countLeafNodes(root->right);
}

int height(Node* root) {
    if (root == nullptr)
        return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return 1 + max(leftHeight, rightHeight);
}

int main() {
    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->right = new Node(6);

    cout << "Number of nodes = "
         << countNodes(root) << endl;

    cout << "Number of leaf nodes = "
         << countLeafNodes(root) << endl;

    cout << "Tree height = "
         << height(root) << endl;

    return 0;
}
