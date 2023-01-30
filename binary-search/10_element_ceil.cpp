#include <bits/stdc++.h>

using namespace std;

void stayTORO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

class Solution {
   public:
    int elementCeil(const vector<int> &arr, const int search) {
        int start = 0;
        int end = arr.size() - 1;
        int ceil = INT_MAX;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (arr[mid] == search) {
                if (mid + 1 > end) {
                    return -1;
                } else {
                    return arr[mid + 1];
                }
            } else if (arr[mid] > search) {
                ceil = min(ceil, arr[mid]);
            }

            if (arr[mid] > search) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        if (ceil == INT_MAX) {
            return -1;
        } else {
            return ceil;
        }
    }
};

int main() {
    stayTORO();

    int n;
    cin >> n;

    vector<int> arr(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int search;
    cin >> search;

    Solution S;

    cout << S.elementCeil(arr, search);

    return 0;
}

// == IN ==
// 6
// 5 10 20 30 40 50
// 21

// == OUT ==
// 30
