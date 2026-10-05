#include <iostream>
using namespace std;

int firstOccurrence(int arr[], int n, int target) {
    int left = 0, right = n - 1;
    int answer = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            answer = mid;
            right = mid - 1;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return answer;
}

int lastOccurrence(int arr[], int n, int target) {
    int left = 0, right = n - 1;
    int answer = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            answer = mid;
            left = mid + 1;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return answer;
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
    cout << "Enter value: ";
    cin >> target;

    int first = firstOccurrence(arr, n, target);
    int last = lastOccurrence(arr, n, target);

    if (first == -1) {
        cout << "Value not found.\n";
    } else {
        cout << "First occurrence = " << first << endl;
        cout << "Last occurrence = " << last << endl;
        cout << "Total occurrences = " << last - first + 1 << endl;
    }

    return 0;
}
