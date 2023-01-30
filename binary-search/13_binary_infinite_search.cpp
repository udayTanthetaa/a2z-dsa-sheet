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
    int binaryInfiniteSearch(const vector<int> &arr, const int search) {
        int start = 0;
        int end = 1;

        int candidate = -1;

        while (arr[end] != search) {
            start = end;
            end *= 2;
        }

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (arr[mid] == search) {
                candidate = mid;
                end = mid - 1;
            } else if (arr[mid] < search) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        return candidate;
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

    cout << S.binaryInfiniteSearch(arr, search);

    return 0;
}

// == IN ==
// 11
// 0 0 0 0 0 0 1 1 1 1 1
// 1

// == OUT ==
// 6
