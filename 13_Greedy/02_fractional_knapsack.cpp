#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

struct Item {
    int weight;
    int value;
    double ratio;
};

bool compareRatio(Item a, Item b) {
    return a.ratio > b.ratio;
}

int main() {
    int n, capacity;

    cout << "Enter number of items: ";
    cin >> n;

    vector<Item> items(n);

    cout << "Enter weight and value of each item:\n";

    for (int i = 0; i < n; i++) {
        cin >> items[i].weight >> items[i].value;

        if (items[i].weight > 0)
            items[i].ratio =
                (double)items[i].value / items[i].weight;
        else
            items[i].ratio = 0;
    }

    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    sort(items.begin(), items.end(), compareRatio);

    double totalValue = 0;
    int remaining = capacity;

    for (const Item& item : items) {
        if (remaining == 0)
            break;

        if (item.weight <= remaining) {
            totalValue += item.value;
            remaining -= item.weight;
        } else {
            totalValue += item.ratio * remaining;
            remaining = 0;
        }
    }

    cout << fixed << setprecision(2);
    cout << "\nMaximum value = " << totalValue << "\n";

    return 0;
}
