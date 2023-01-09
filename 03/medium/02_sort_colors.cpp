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

// Dutch National Flag Problem

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0;
        int mid = 0;
        int high = nums.size() - 1;

        while(mid <= high) {
            switch(nums[mid]) {
                case 0:
                    swap(nums[low++], nums[mid++]);
                    break;
                case 1:
                    mid++;
                    break;
                case 2:
                    swap(nums[mid], nums[high--]);
                    break;
            }
        }
    }
};

int main() {
	stayTORO();

    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i<n; i++) {
        cin >> arr[i];
    }

    Solution S;
    S.sortColors(arr);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}

// == IN ==
// 6
// 2 0 2 1 1 0

// == OUT ==
// 0 0 1 1 2 2
