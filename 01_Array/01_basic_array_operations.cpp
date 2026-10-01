#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter array size: ";
    cin >> n;

    int arr[n];

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << "\nArray elements: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";

    int sum = 0;
    for (int i = 0; i < n; i++) sum += arr[i];

    int maximum = arr[0];
    int minimum = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > maximum) maximum = arr[i];
        if (arr[i] < minimum) minimum = arr[i];
    }

    cout << "\nSum = " << sum << endl;
    cout << "Maximum = " << maximum << endl;
    cout << "Minimum = " << minimum << endl;

    return 0;
}
