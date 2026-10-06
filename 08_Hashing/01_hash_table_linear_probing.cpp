#include <iostream>
using namespace std;

const int SIZE = 10;
const int EMPTY = -1;

class HashTable {
private:
    int table[SIZE];

    int hashFunction(int key) {
        return key % SIZE;
    }

public:
    HashTable() {
        for (int i = 0; i < SIZE; i++)
            table[i] = EMPTY;
    }

    void insert(int key) {
        int index = hashFunction(key);

        for (int i = 0; i < SIZE; i++) {
            int position = (index + i) % SIZE;

            if (table[position] == EMPTY) {
                table[position] = key;
                cout << "Inserted at index " << position << ".\n";
                return;
            }
        }

        cout << "Hash table is full.\n";
    }

    void search(int key) {
        int index = hashFunction(key);

        for (int i = 0; i < SIZE; i++) {
            int position = (index + i) % SIZE;

            if (table[position] == EMPTY) {
                cout << "Value not found.\n";
                return;
            }

            if (table[position] == key) {
                cout << "Value found at index " << position << ".\n";
                return;
            }
        }

        cout << "Value not found.\n";
    }

    void display() {
        cout << "\nHash Table:\n";

        for (int i = 0; i < SIZE; i++) {
            cout << i << " : ";

            if (table[i] == EMPTY)
                cout << "EMPTY";
            else
                cout << table[i];

            cout << endl;
        }
    }
};

int main() {
    HashTable hashTable;
    int choice, value;

    do {
        cout << "\n===== Hash Table - Linear Probing =====\n";
        cout << "1. Insert\n";
        cout << "2. Search\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                hashTable.insert(value);
                break;

            case 2:
                cout << "Enter value to search: ";
                cin >> value;
                hashTable.search(value);
                break;

            case 3:
                hashTable.display();
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
