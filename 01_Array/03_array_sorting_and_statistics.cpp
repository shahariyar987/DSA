#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter array size: ";
    cin >> n;

    int arr[n];

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) cin >> arr[i];

    // Bubble Sort
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    cout << "\nSorted array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";

    int sum = 0;
    for (int i = 0; i < n; i++) sum += arr[i];

    double average = (double)sum / n;

    cout << "\n\nSum = " << sum;
    cout << "\nAverage = " << average;
    cout << "\nMinimum = " << arr[0];
    cout << "\nMaximum = " << arr[n - 1];

    if (n % 2 == 1)
        cout << "\nMedian = " << arr[n / 2];
    else
        cout << "\nMedian = " << (arr[n / 2 - 1] + arr[n / 2]) / 2.0;

    cout << endl;
    return 0;
}
