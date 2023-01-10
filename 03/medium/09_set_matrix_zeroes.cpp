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
    void setZeroes(vector<vector<int>>& matrix) {
        // n -> rows
        // m -> columns
        int n = matrix.size();
        int m = matrix[0].size();

        int col0 = -1;

        for (int i = 0; i < n; i++) {
            if(matrix[i][0] == 0) {
                col0 = 0;
            }

            for (int j = 1; j < m; j++) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for(int i = n-1; i >= 0; i--) {
            for(int j = m-1; j >= 1; j--) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }

            if(col0 == 0) {
                matrix[i][0] = 0;
            }
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
    S.setZeroes(arr);

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
// 1 1 1
// 1 0 1
// 1 1 1

// == OUT ==
// 1 0 1 
// 0 0 0 
// 1 0 1 
