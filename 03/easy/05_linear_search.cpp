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
    bool search(const vector<int>& nums, const int num) {
        for (int i = 0; i < nums.size(); i++) {
            if(nums[i] == num) {
                return true;
            }
        }

        return false;
    }
};


int main() {
	stayTORO();

    Solution S;

    int n;
    cin>>n;

    vector<int> arr(n);

    for (int i = 0; i<n; i++) {
        cin >> arr[i];
    }

    int num;
    cin >> num;

    cout<<S.search(arr, num);

    return 0;
}

// == IN ==
// 5
// 0 1 0 3 2
// 5

// == OUT ==
// 0
