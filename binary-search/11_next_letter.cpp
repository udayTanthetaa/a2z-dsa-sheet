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
    char nextLetter(const vector<char> &arr, const char search) {
        int start = 0;
        int end = arr.size() - 1;

        char nextLetter = '@';

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (arr[mid] == search) {
                if (mid + 1 > arr.size() - 1) {
                    return '@';
                } else {
                    return arr[mid + 1];
                }
            } else if (arr[mid] > search) {
                nextLetter = arr[mid];
            }

            if (arr[mid] > search) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return nextLetter;
    }
};

int main() {
    stayTORO();

    int n;
    cin >> n;

    vector<char> arr(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    char search;
    cin >> search;

    Solution S;

    cout << S.nextLetter(arr, search);

    return 0;
}

// == IN ==
// 4
// a c f h
// f

// == OUT ==
// h
