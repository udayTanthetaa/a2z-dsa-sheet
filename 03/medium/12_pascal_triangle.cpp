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
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascal(numRows);

        for (int i = 0; i < numRows; i++) {
            pascal[i].resize(i + 1);
            pascal[i][0] = pascal[i][i] = 1;

            for (int j = 1; j < i; j++) {
                pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
            }
        }

        return pascal;
    }
};

int main() {
	stayTORO();

    int rows;
    cin >> rows;

    Solution S;
    vector<vector<int>> pascal = S.generate(rows);

    for (int i = 0; i < pascal.size(); i++) {
        for (int j = 0; j < pascal[i].size(); j++) {
            cout << pascal[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

// == IN ==
// 5

// == OUT ==
// 1 
// 1 1 
// 1 2 1 
// 1 3 3 1 
// 1 4 6 4 1 