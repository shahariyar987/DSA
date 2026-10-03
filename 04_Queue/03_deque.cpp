#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

class Deque {
private:
    int data[MAX_SIZE];
    int front;
    int rear;

public:
    Deque() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return (front == 0 && rear == MAX_SIZE - 1) ||
               (front == rear + 1);
    }

    void insertFront(int value) {
        if (isFull()) {
            cout << "Deque is full.\n";
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else if (front == 0) {
            front = MAX_SIZE - 1;
        } else {
            front--;
        }

        data[front] = value;
    }

    void insertRear(int value) {
        if (isFull()) {
            cout << "Deque is full.\n";
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else if (rear == MAX_SIZE - 1) {
            rear = 0;
        } else {
            rear++;
        }

        data[rear] = value;
    }

    void deleteFront() {
        if (isEmpty()) {
            cout << "Deque is empty.\n";
            return;
        }

        cout << "Deleted: " << data[front] << endl;

        if (front == rear) {
            front = rear = -1;
        } else if (front == MAX_SIZE - 1) {
            front = 0;
        } else {
            front++;
        }
    }

    void deleteRear() {
        if (isEmpty()) {
            cout << "Deque is empty.\n";
            return;
        }

        cout << "Deleted: " << data[rear] << endl;

        if (front == rear) {
            front = rear = -1;
        } else if (rear == 0) {
            rear = MAX_SIZE - 1;
        } else {
            rear--;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Deque is empty.\n";
            return;
        }

        cout << "Deque: ";

        int i = front;
        while (true) {
            cout << data[i] << " ";
            if (i == rear) break;
            i = (i + 1) % MAX_SIZE;
        }

        cout << endl;
    }
};

int main() {
    Deque dq;
    int choice, value;

    do {
        cout << "\n===== Deque =====\n";
        cout << "1. Insert Front\n";
        cout << "2. Insert Rear\n";
        cout << "3. Delete Front\n";
        cout << "4. Delete Rear\n";
        cout << "5. Display\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                dq.insertFront(value);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> value;
                dq.insertRear(value);
                break;

            case 3:
                dq.deleteFront();
                break;

            case 4:
                dq.deleteRear();
                break;

            case 5:
                dq.display();
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
