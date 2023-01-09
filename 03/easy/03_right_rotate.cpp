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
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();

        vector<int> arr(nums.size());

        for (int i = 0; i < nums.size(); i++) {
            arr[(i + k) % nums.size()] = nums[i];
        }

        for (int i = 0; i < nums.size(); i++) {
            nums[i] = arr[i];
        }
    }
};

// n = 5
// arr = [ 1 2 3 4 5 ]

// 5 1 2 3 4 1st rotation
// 4 5 1 2 3 2nd rotation

// rotations = 2

// -> 0 to 2
// -> 1 to 3
// -> 2 to 4
// -> 3 to 0
// -> 4 -> 1

// Formula = index is going to (index + rotations) % n

int main() {
	stayTORO();

    Solution S;

    int n, rotations;
    cin>>n;

    vector<int> arr(n);

    for (int i = 0; i<n; i++) {
        cin >> arr[i];
    }

    cin >> rotations;

    S.rotate(arr, rotations);

    for (int i=0; i<arr.size(); i++) {
        cout << arr[i] << " ";
    }

    return 0;
}

// == IN ==
// 5
// 1 2 3 4 5
// 2

// == OUT ==
// 4 5 1 2 3 
