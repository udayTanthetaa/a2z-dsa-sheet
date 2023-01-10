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
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int top = 0;
        int bottom = matrix.size() - 1;
        int left = 0;
        int right = matrix[0].size() - 1;

        vector<int> order;

        while (top <= bottom && left <= right) {
            // First Row
            for (int i = left; i <= right; i++) {
                order.push_back(matrix[top][i]);
            }

            top++;

            // Last Column
            for (int i = top; i <= bottom; i++) {
                order.push_back(matrix[i][right]);
            }

            right--;
            
            if(top <= bottom) {
                // Last Row
                for (int i = right; i >= left; i--) {
                    order.push_back(matrix[bottom][i]);
                }

                bottom--;
            }

            if(left <= right) {
                // First Column
                for (int i = bottom; i >= top; i--) {
                    order.push_back(matrix[i][left]);
                }

                left++;
            }
        }

        return order;
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
    vector<int> order = S.spiralOrder(arr);

    for (int i = 0; i < order.size(); i++) {
        cout << order[i] << " ";
    }

    return 0;
}

// == IN ==
// 3 3
// 1 2 3
// 8 9 4
// 7 6 5

// == OUT ==
// 1 2 3 4 5 6 7 8 9