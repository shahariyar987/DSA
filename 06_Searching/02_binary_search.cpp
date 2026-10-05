#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int target) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;

        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

int main() {
    int n;

    cout << "Enter sorted array size: ";
    cin >> n;

    int arr[n];

    cout << "Enter sorted elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int target;
    cout << "Enter value to search: ";
    cin >> target;

    int result = binarySearch(arr, n, target);

    if (result == -1)
        cout << "Value not found.\n";
    else
        cout << "Value found at index " << result << ".\n";

    return 0;
}
