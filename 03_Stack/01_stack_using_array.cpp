#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

int main() {
    int stack[MAX_SIZE];
    int top = -1;
    int choice, value;

    do {
        cout << "\n===== Stack =====\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (top == MAX_SIZE - 1) {
                    cout << "Stack Overflow.\n";
                } else {
                    cout << "Enter value: ";
                    cin >> value;
                    stack[++top] = value;
                    cout << "Value pushed.\n";
                }
                break;

            case 2:
                if (top == -1) {
                    cout << "Stack Underflow.\n";
                } else {
                    cout << "Popped value: " << stack[top--] << endl;
                }
                break;

            case 3:
                if (top == -1)
                    cout << "Stack is empty.\n";
                else
                    cout << "Top value: " << stack[top] << endl;
                break;

            case 4:
                if (top == -1) {
                    cout << "Stack is empty.\n";
                } else {
                    cout << "Stack: ";
                    for (int i = top; i >= 0; i--) cout << stack[i] << " ";
                    cout << endl;
                }
                break;

            case 5:
                cout << "Program terminated.\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 5);

    return 0;
}
