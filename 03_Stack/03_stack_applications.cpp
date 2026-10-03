#include <iostream>
#include <string>
using namespace std;

const int MAX_SIZE = 100;

bool isMatching(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

bool isBalanced(const string& expression) {
    char stack[MAX_SIZE];
    int top = -1;

    for (char ch : expression) {
        if (ch == '(' || ch == '{' || ch == '[') {
            if (top == MAX_SIZE - 1) return false;
            stack[++top] = ch;
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (top == -1) return false;
            if (!isMatching(stack[top], ch)) return false;
            top--;
        }
    }

    return top == -1;
}

bool isPalindrome(const string& text) {
    char stack[MAX_SIZE];
    int top = -1;

    if (text.length() > MAX_SIZE) return false;

    for (char ch : text) stack[++top] = ch;

    for (char ch : text) {
        if (ch != stack[top--]) return false;
    }

    return true;
}

int main() {
    int choice;

    do {
        cout << "\n===== Stack Applications =====\n";
        cout << "1. Check Balanced Parentheses\n";
        cout << "2. Check Palindrome\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            string expression;
            cout << "Enter expression: ";
            cin >> expression;

            if (isBalanced(expression))
                cout << "Parentheses are balanced.\n";
            else
                cout << "Parentheses are NOT balanced.\n";
        } else if (choice == 2) {
            string text;
            cout << "Enter text: ";
            cin >> text;

            if (isPalindrome(text))
                cout << "It is a palindrome.\n";
            else
                cout << "It is NOT a palindrome.\n";
        } else if (choice == 3) {
            cout << "Program terminated.\n";
        } else {
            cout << "Invalid choice.\n";
        }

    } while (choice != 3);

    return 0;
}
