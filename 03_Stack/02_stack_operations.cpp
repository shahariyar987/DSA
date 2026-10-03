#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

void push(int stack[], int& top, int value) {
    if (top == MAX_SIZE - 1) {
        cout << "Stack Overflow.\n";
        return;
    }
    stack[++top] = value;
}

void pop(int stack[], int& top) {
    if (top == -1) {
        cout << "Stack Underflow.\n";
        return;
    }
    cout << "Popped: " << stack[top--] << endl;
}

void display(int stack[], int top) {
    if (top == -1) {
        cout << "Stack is empty.\n";
        return;
    }

    cout << "Stack: ";
    for (int i = top; i >= 0; i--) cout << stack[i] << " ";
    cout << endl;
}

void findMinimum(int stack[], int top) {
    if (top == -1) {
        cout << "Stack is empty.\n";
        return;
    }

    int minimum = stack[0];
    for (int i = 1; i <= top; i++)
        if (stack[i] < minimum) minimum = stack[i];

    cout << "Minimum = " << minimum << endl;
}

void findMaximum(int stack[], int top) {
    if (top == -1) {
        cout << "Stack is empty.\n";
        return;
    }

    int maximum = stack[0];
    for (int i = 1; i <= top; i++)
        if (stack[i] > maximum) maximum = stack[i];

    cout << "Maximum = " << maximum << endl;
}

int main() {
    int stack[MAX_SIZE];
    int top = -1;
    int choice, value;

    do {
        cout << "\n===== Stack Operations =====\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Display\n";
        cout << "4. Find Minimum\n";
        cout << "5. Find Maximum\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                push(stack, top, value);
                break;
            case 2:
                pop(stack, top);
                break;
            case 3:
                display(stack, top);
                break;
            case 4:
                findMinimum(stack, top);
                break;
            case 5:
                findMaximum(stack, top);
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
