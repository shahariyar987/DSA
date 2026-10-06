#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right) {
    int size1 = mid - left + 1;
    int size2 = right - mid;

    int leftArray[size1];
    int rightArray[size2];

    for (int i = 0; i < size1; i++)
        leftArray[i] = arr[left + i];

    for (int i = 0; i < size2; i++)
        rightArray[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;

    while (i < size1 && j < size2) {
        if (leftArray[i] <= rightArray[j])
            arr[k++] = leftArray[i++];
        else
            arr[k++] = rightArray[j++];
    }

    while (i < size1)
        arr[k++] = leftArray[i++];

    while (j < size2)
        arr[k++] = rightArray[j++];
}

void mergeSort(int arr[], int left, int right) {
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

int partitionArray(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;

            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low >= high)
        return;

    int pivotIndex = partitionArray(arr, low, high);

    quickSort(arr, low, pivotIndex - 1);
    quickSort(arr, pivotIndex + 1, high);
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

    int mergeArray[n];
    int quickArray[n];

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> mergeArray[i];
        quickArray[i] = mergeArray[i];
    }

    mergeSort(mergeArray, 0, n - 1);
    quickSort(quickArray, 0, n - 1);

    cout << "\nMerge Sort: ";
    display(mergeArray, n);

    cout << "Quick Sort: ";
    display(quickArray, n);

    return 0;
}
