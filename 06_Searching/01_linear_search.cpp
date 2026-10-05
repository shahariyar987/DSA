#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target)
            return i;
    }

    return -1;
}

int main() {
    int n;

    cout << "Enter array size: ";
    cin >> n;

    int arr[n];

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int target;
    cout << "Enter value to search: ";
    cin >> target;

    int result = linearSearch(arr, n, target);

    if (result == -1)
        cout << "Value not found.\n";
    else
        cout << "Value found at index " << result << ".\n";

    return 0;
}
