#include <iostream>
using namespace std;

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minimumIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minimumIndex])
                minimumIndex = j;
        }

        int temp = arr[i];
        arr[i] = arr[minimumIndex];
        arr[minimumIndex] = temp;
    }
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

void display(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int n;

    cout << "Enter array size: ";
    cin >> n;

    int arr1[n], arr2[n];

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
        arr2[i] = arr1[i];
    }

    selectionSort(arr1, n);
    insertionSort(arr2, n);

    cout << "\nSelection Sort: ";
    display(arr1, n);

    cout << "Insertion Sort: ";
    display(arr2, n);

    return 0;
}
