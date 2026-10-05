#include <iostream>
using namespace std;

int binarySearch(int arr[], int left, int right, int target) {
    if (left > right)
        return -1;

    int mid = left + (right - left) / 2;

    if (arr[mid] == target)
        return mid;

    if (target < arr[mid])
        return binarySearch(arr, left, mid - 1, target);

    return binarySearch(arr, mid + 1, right, target);
}

void towerOfHanoi(int n, char source, char auxiliary, char destination) {
    if (n == 0)
        return;

    towerOfHanoi(n - 1, source, destination, auxiliary);

    cout << "Move disk " << n
         << " from " << source
         << " to " << destination << endl;

    towerOfHanoi(n - 1, auxiliary, source, destination);
}

int main() {
    int n;

    cout << "Enter sorted array size: ";
    cin >> n;

    int arr[n];

    cout << "Enter " << n << " sorted elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int target;
    cout << "Enter value to search: ";
    cin >> target;

    int result = binarySearch(arr, 0, n - 1, target);

    if (result == -1)
        cout << "Value not found.\n";
    else
        cout << "Value found at index " << result << ".\n";

    int disks;
    cout << "\nEnter number of disks for Tower of Hanoi: ";
    cin >> disks;

    if (disks < 0) {
        cout << "Invalid number of disks.\n";
        return 0;
    }

    cout << "\nTower of Hanoi moves:\n";
    towerOfHanoi(disks, 'A', 'B', 'C');

    return 0;
}
