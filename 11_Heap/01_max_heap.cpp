#include <iostream>
using namespace std;

class MaxHeap {
private:
    int heap[100];
    int size;

    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;

            if (heap[parent] >= heap[index])
                break;

            swap(heap[parent], heap[index]);
            index = parent;
        }
    }

    void heapifyDown(int index) {
        while (true) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int largest = index;

            if (left < size && heap[left] > heap[largest])
                largest = left;

            if (right < size && heap[right] > heap[largest])
                largest = right;

            if (largest == index)
                break;

            swap(heap[index], heap[largest]);
            index = largest;
        }
    }

public:
    MaxHeap() {
        size = 0;
    }

    void insert(int value) {
        heap[size] = value;
        heapifyUp(size);
        size++;
    }

    void removeMax() {
        if (size == 0) {
            cout << "Heap is empty.\n";
            return;
        }

        cout << "Removed maximum: " << heap[0] << endl;

        heap[0] = heap[size - 1];
        size--;

        if (size > 0)
            heapifyDown(0);
    }

    void display() {
        if (size == 0) {
            cout << "Heap is empty.\n";
            return;
        }

        cout << "Max Heap: ";

        for (int i = 0; i < size; i++)
            cout << heap[i] << " ";

        cout << endl;
    }
};

int main() {
    MaxHeap heap;
    int choice, value;

    do {
        cout << "\n===== Max Heap =====\n";
        cout << "1. Insert\n";
        cout << "2. Remove Maximum\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                heap.insert(value);
                break;

            case 2:
                heap.removeMax();
                break;

            case 3:
                heap.display();
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
