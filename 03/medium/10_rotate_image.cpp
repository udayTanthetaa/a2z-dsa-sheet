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
    void rotate(vector<vector<int>>& matrix) {
        // n -> rows
        // m -> cols
        int n = matrix.size();
        int m = matrix[0].size();

        // Finding Transpose
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Reversing rows
        for (int i = 0; i<n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

int main() {
	stayTORO();

    int r, c;
    cin >> r >> c;

    vector<vector<int>> arr(r, vector<int> (c, 0));

    for (int i = 0; i<r; i++) {
        for (int j = 0; j<c; j++) {
            cin >> arr[i][j];
        }
    }

    Solution S;
    S.rotate(arr);

    for (int i = 0; i<r; i++) {
        for (int j = 0; j<c; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

// == IN ==
// 3 3
// 1 2 3
// 4 5 6
// 7 8 9

// == OUT ==
// 1 0 1 
// 0 0 0 
// 1 0 1 
