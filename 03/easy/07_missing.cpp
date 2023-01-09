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
    int missing(const vector<int>& nums) {
        // a -> missing

        int n = nums.size();
        int arrSn = 0;

        for(int i = 0; i < nums.size(); i++) {
            arrSn += nums[i];
        }

        int Sn = (n * (n + 1)) / 2;

        return (Sn - arrSn);
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

    cout<<S.missing(arr);

    return 0;
}

// == IN ==
// 5
// 1 2 3 4 0

// == OUT ==
// 5
