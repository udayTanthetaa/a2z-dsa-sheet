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
    int minimumDifference(const vector<int> &arr, const int search) {
        int start = 0;
        int end = arr.size() - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (arr[mid] == search) {
                return 0;
            } else if (arr[mid] > search) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return min(abs(arr[start] - search), abs(arr[end] - search));
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

    cout << S.minimumDifference(arr, search);

    return 0;
}

// == IN ==
// 5
// 1 3 8 10 15
// 12

// == OUT ==
// 10
