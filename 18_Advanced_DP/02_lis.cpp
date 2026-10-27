#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    if (n == 0) {
        cout << "LIS length = 0\n";
        return 0;
    }

    vector<int> dp(n, 1);
    vector<int> parent(n, -1);

    int bestLength = 1;
    int bestIndex = 0;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i] &&
                dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                parent[i] = j;
            }
        }

        if (dp[i] > bestLength) {
            bestLength = dp[i];
            bestIndex = i;
        }
    }

    vector<int> lis;

    for (int index = bestIndex;
         index != -1;
         index = parent[index]) {
        lis.push_back(arr[index]);
    }

    reverse(lis.begin(), lis.end());

    cout << "\nLIS length = " << bestLength << "\n";
    cout << "LIS: ";

    for (int value : lis)
        cout << value << " ";

    cout << "\n";

    return 0;
}
