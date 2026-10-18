#include <iostream>
#include <vector>
using namespace std;

bool findSubset(const vector<int>& arr,
                int index,
                int target,
                vector<int>& current) {
    if (target == 0)
        return true;

    if (index == (int)arr.size() || target < 0)
        return false;

    current.push_back(arr[index]);

    if (findSubset(arr, index + 1,
                   target - arr[index], current))
        return true;

    current.pop_back();

    if (findSubset(arr, index + 1,
                   target, current))
        return true;

    return false;
}

int main() {
    int n, target;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter target sum: ";
    cin >> target;

    vector<int> subset;

    if (findSubset(arr, 0, target, subset)) {
        cout << "\nSubset found: ";

        for (int value : subset)
            cout << value << " ";

        cout << "\n";
    } else {
        cout << "No subset with the target sum was found.\n";
    }

    return 0;
}
