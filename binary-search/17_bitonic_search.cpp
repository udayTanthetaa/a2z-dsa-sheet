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
    int bitonicMax(const vector<int> &arr) {
        int start = 0;
        int end = arr.size() - 1;

        int mid = -1;

        while (start <= end) {
            mid = start + (end - start) / 2;

            if ((arr[mid] == 0 || arr[mid] > arr[mid - 1]) &&
                (arr[mid] == arr.size() - 1 || arr[mid] > arr[mid + 1])) {
                break;
            }

            if (mid > 0 && arr[mid - 1] > arr[mid]) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return mid;
    }

    int binarySearchAsc(const vector<int> &arr, const int search) {
        int start = 0;
        int end = arr.size() - 1;

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

    int binarySearchDsc(const vector<int> &arr, const int search) {
        int start = 0;
        int end = arr.size() - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (arr[mid] == search) {
                return mid;
            } else if (arr[mid] < search) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return -1;
    }

    int bitonicSearch(const vector<int> &arr, const int search) {
        int maxIndex = bitonicMax(arr);

        int ascAnswer, dscAnswer;

        ascAnswer = binarySearchAsc(arr, search);

        if (ascAnswer != -1) {
            return ascAnswer;
        } else {
            dscAnswer = binarySearchDsc(arr, search);
            return dscAnswer;
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

    cout << S.bitonicSearch(arr, search);

    return 0;
}

// == IN ==
// 6
// 1 3 8 12 4 2
// 8

// == OUT ==
// 2
