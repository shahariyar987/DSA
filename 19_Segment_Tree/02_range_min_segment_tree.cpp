#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class SegmentTree {
    int n;
    vector<int> tree;

    void build(const vector<int>& arr,
               int node,
               int left,
               int right) {
        if (left == right) {
            tree[node] = arr[left];
            return;
        }

        int mid = (left + right) / 2;

        build(arr, node * 2, left, mid);
        build(arr, node * 2 + 1, mid + 1, right);

        tree[node] =
            min(tree[node * 2],
                tree[node * 2 + 1]);
    }

    int query(int node,
              int left,
              int right,
              int queryLeft,
              int queryRight) {
        if (queryRight < left ||
            right < queryLeft)
            return INT_MAX;

        if (queryLeft <= left &&
            right <= queryRight)
            return tree[node];

        int mid = (left + right) / 2;

        return min(
            query(node * 2, left, mid,
                  queryLeft, queryRight),
            query(node * 2 + 1, mid + 1, right,
                  queryLeft, queryRight)
        );
    }

public:
    SegmentTree(const vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        build(arr, 1, 0, n - 1);
    }

    int rangeMinimum(int left, int right) {
        return query(1, 0, n - 1, left, right);
    }
};

int main() {
    int n;

    cout << "Enter array size: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter array elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    SegmentTree tree(arr);

    int left, right;

    cout << "Enter query range (left right): ";
    cin >> left >> right;

    if (left >= 0 && right < n && left <= right)
        cout << "Range minimum = "
             << tree.rangeMinimum(left, right) << "\n";
    else
        cout << "Invalid range.\n";

    return 0;
}
