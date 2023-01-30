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
    int infiniteSearch(const vector<int> &arr, const int search) {
        int start = 0;
        int end = 1;

        while (arr[end] < search) {
            start = end;
            end *= 2;
        }

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (arr[mid] == search) {
                return mid;
            } else if (arr[mid] < search) {
                start = mid + 1;

            } else {
                end = mid - 1;
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

    cout << S.infiniteSearch(arr, search);

    return 0;
}

// == IN ==
// 11
// 3 5 7 9 10 90 100 130 140 160 170
// 90

// == OUT ==
// 5
