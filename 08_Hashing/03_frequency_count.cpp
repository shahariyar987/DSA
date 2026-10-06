#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    unordered_map<int, int> frequency;

    cout << "Enter elements:\n";

    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        frequency[value]++;
    }

    cout << "\nFrequencies:\n";

    for (auto item : frequency)
        cout << item.first << " -> " << item.second << endl;

    int target;

    cout << "\nEnter value to check frequency: ";
    cin >> target;

    cout << "Frequency of " << target
         << " = " << frequency[target] << endl;

    return 0;
}
