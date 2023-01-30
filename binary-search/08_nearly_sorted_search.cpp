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
    int nearlySortedSearch(const vector<int> &arr, const int search) {
        int start = 0;
        int end = arr.size() - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (arr[mid] == search) {
                return mid;
            } else if (start >= mid - 1 && arr[mid - 1] == search) {
                return mid - 1;
            } else if (end <= mid + 1 && arr[mid + 1] == search) {
                return mid + 1;
            } else if (arr[mid] > search) {
                end = mid - 2;
            } else {
                start = mid + 2;
            }
        }

        return -1;
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

    cout << S.nearlySortedSearch(arr, search);

    return 0;
}

// == IN ==
// 6
// 5 10 30 20 60 40
// 60

// == OUT ==
// 4
