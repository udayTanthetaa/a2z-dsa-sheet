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
    int firstOccurrence(const vector<int> &arr, const int search) {
        int start = 0;
        int end = arr.size() - 1;
        int ans = -1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (arr[mid] == search) {
                ans = mid;
                end = mid - 1;
            } else if (search < arr[mid]) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return ans;
    }

    int lastOccurrence(const vector<int> &arr, const int search) {
        int start = 0;
        int end = arr.size() - 1;
        int ans = -1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (arr[mid] == search) {
                ans = mid;
                start = mid + 1;
            } else if (search < arr[mid]) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return ans;
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

    int firstIndex = S.firstOccurrence(arr, search);
    int lastIndex = S.lastOccurrence(arr, search);

    if (firstIndex == -1) {
        cout << firstIndex;
    } else {
        cout << lastIndex - firstIndex + 1;
    }

    return 0;
}

// == IN ==
// 6
// 1 2 3 4 4 6
// 4

// == OUT ==
// 2
