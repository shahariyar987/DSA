#include <iostream>
using namespace std;

const int MAX_SIZE = 5;

class CircularQueue {
private:
    int queue[MAX_SIZE];
    int front;
    int rear;
    int count;

public:
    CircularQueue() {
        front = 0;
        rear = -1;
        count = 0;
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == MAX_SIZE;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full.\n";
            return;
        }

        rear = (rear + 1) % MAX_SIZE;
        queue[rear] = value;
        count++;

        cout << "Value inserted.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }

        cout << "Dequeued value: " << queue[front] << endl;

        front = (front + 1) % MAX_SIZE;
        count--;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }

        cout << "Circular Queue: ";

        for (int i = 0; i < count; i++)
            cout << queue[(front + i) % MAX_SIZE] << " ";

        cout << endl;
    }
};

int main() {
    CircularQueue q;
    int choice, value;

    do {
        cout << "\n===== Circular Queue =====\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                q.enqueue(value);
                break;

            case 2:
                q.dequeue();
                break;

            case 3:
                q.display();
                break;

            case 4:
                cout << "Program terminated.\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 4);

    return 0;
}
