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
    tuple<int, int> matrixSearch(vector<vector<int>>& matrix, int search) {
        int i = 0;
        int j = matrix[0].size() - 1;

        while (i <= matrix.size() && j >= 0) {
            if (matrix[i][j] == search) {
                return make_tuple(i, j);
            } else if (matrix[i][j] > search) {
                j--;
            } else {
                i++;
            }
        }

        return make_tuple(-1, -1);
    }
};

int main() {
    stayTORO();

    int r, c;
    cin >> r >> c;

    vector<vector<int>> arr(r, vector<int>(c, 0));

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> arr[i][j];
        }
    }

    int search;
    cin >> search;

    Solution S;

    int i, j;
    tie(i, j) = S.matrixSearch(arr, search);

    cout << i << " " << j;

    return 0;
}

// == IN ==
// 4 4
// 10 20 30 40
// 15 25 35 45
// 27 29 37 48
// 32 33 39 50
// 29

// == OUT ==
// 2 1
