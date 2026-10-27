#include <iostream>
#include <vector>
using namespace std;

class SegmentTree {
    int n;
    vector<long long> tree;

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
            tree[node * 2] +
            tree[node * 2 + 1];
    }

    long long query(int node,
                    int left,
                    int right,
                    int queryLeft,
                    int queryRight) {
        if (queryLeft <= left &&
            right <= queryRight)
            return tree[node];

        if (right < queryLeft ||
            left > queryRight)
            return 0;

        int mid = (left + right) / 2;

        return query(node * 2, left, mid,
                     queryLeft, queryRight)
             + query(node * 2 + 1, mid + 1, right,
                     queryLeft, queryRight);
    }

public:
    SegmentTree(const vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        build(arr, 1, 0, n - 1);
    }

    long long rangeSum(int left, int right) {
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
        cout << "Range sum = "
             << tree.rangeSum(left, right) << "\n";
    else
        cout << "Invalid range.\n";

    return 0;
}
