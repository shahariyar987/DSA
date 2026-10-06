#include <iostream>
#include <vector>
using namespace std;

const int SIZE = 7;

class HashTable {
private:
    vector<int> table[SIZE];

    int hashFunction(int key) {
        return key % SIZE;
    }

public:
    void insert(int key) {
        int index = hashFunction(key);
        table[index].push_back(key);

        cout << "Inserted into bucket " << index << ".\n";
    }

    void search(int key) {
        int index = hashFunction(key);

        for (int value : table[index]) {
            if (value == key) {
                cout << "Value found in bucket " << index << ".\n";
                return;
            }
        }

        cout << "Value not found.\n";
    }

    void display() {
        cout << "\nHash Table:\n";

        for (int i = 0; i < SIZE; i++) {
            cout << i << " : ";

            if (table[i].empty()) {
                cout << "EMPTY";
            } else {
                for (int value : table[i])
                    cout << value << " -> ";
                cout << "NULL";
            }

            cout << endl;
        }
    }
};

int main() {
    HashTable hashTable;
    int choice, value;

    do {
        cout << "\n===== Hash Table - Chaining =====\n";
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
