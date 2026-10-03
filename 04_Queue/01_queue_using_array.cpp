#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

int main() {
    int queue[MAX_SIZE];
    int front = -1, rear = -1;
    int choice, value;

    do {
        cout << "\n===== Queue =====\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Front\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (rear == MAX_SIZE - 1) {
                    cout << "Queue Overflow.\n";
                } else {
                    cout << "Enter value: ";
                    cin >> value;

                    if (front == -1) front = 0;
                    queue[++rear] = value;

                    cout << "Value inserted.\n";
                }
                break;

            case 2:
                if (front == -1 || front > rear) {
                    cout << "Queue Underflow.\n";
                } else {
                    cout << "Dequeued value: " << queue[front++] << endl;

                    if (front > rear)
                        front = rear = -1;
                }
                break;

            case 3:
                if (front == -1)
                    cout << "Queue is empty.\n";
                else
                    cout << "Front value: " << queue[front] << endl;
                break;

            case 4:
                if (front == -1) {
                    cout << "Queue is empty.\n";
                } else {
                    cout << "Queue: ";
                    for (int i = front; i <= rear; i++)
                        cout << queue[i] << " ";
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
