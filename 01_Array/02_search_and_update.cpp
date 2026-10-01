#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter array size: ";
    cin >> n;

    int arr[n];

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << "\nOriginal array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";

    int value;
    cout << "\n\nEnter value to search: ";
    cin >> value;

    int position = -1;

    for (int i = 0; i < n; i++) {
        if (arr[i] == value) {
            position = i;
            break;
        }
    }

    if (position != -1)
        cout << "Value found at index " << position << endl;
    else
        cout << "Value not found." << endl;

    int index, newValue;
    cout << "\nEnter index to update: ";
    cin >> index;

    if (index >= 0 && index < n) {
        cout << "Enter new value: ";
        cin >> newValue;
        arr[index] = newValue;

        cout << "Array after update: ";
        for (int i = 0; i < n; i++) cout << arr[i] << " ";
        cout << endl;
    } else {
        cout << "Invalid index." << endl;
    }

    return 0;
}
