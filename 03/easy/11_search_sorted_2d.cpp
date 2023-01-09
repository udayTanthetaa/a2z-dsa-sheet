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
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // n -> rows
        // m -> columns
        int n = matrix.size();
        int m = matrix[0].size();

        int low = 0;
        int high = (n * m) - 1;

        while(low <= high) {
            int middle = low + (high - low) / 2;

            int middleEle = matrix[floor(middle / m)][middle % m];

            if(middleEle == target) {
                return true;
            } else if(middleEle < target) {
                low = middle + 1;
            } else {
                high = middle - 1;
            }
        }

        return false;
    }
};


int main() {
	stayTORO();

    Solution S;

    int r, c;
    cin>>r>>c;

    vector<vector<int>> matrix(r, vector<int>(c, 0));

    for (int i = 0; i < r; i++) {
        for (int j = 0; j<c; j++) {
            cin >> matrix[i][j];
        }
    }

    int search;
    cin >> search;

    cout << S.searchMatrix(matrix, search);

    return 0;
}

// == IN ==
// 3 4
// 1 3 5 7
// 10 11 16 20
// 23 30 34 60
// 5

// == OUT ==
// 1
