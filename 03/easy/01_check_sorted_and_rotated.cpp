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

// Logic:
// Find pivot points, such that next element is greater than previous element
// If pivots are greater than or equal to 2, then array is not sorted and rotated

class Solution {
    public:
    bool checkSortedAndRotated(const vector<int> &arr) {
        int pivots = 0;

        for (int i = 0; i < arr.size()-1; i++)
        {
            if(arr[i] > arr[i+1]) {
                pivots++;
            }
        }

        if(arr.size() > 2) {
            if(arr[0] < arr[arr.size()-1]) {
                pivots++;
            }
        }

        if(pivots >= 2) {
            return false;
        } else {
            return true;
        }
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

    cout<<S.checkSortedAndRotated(arr);

    return 0;
}

// == IN ==
// 5
// 5 1 2 3 4

// == OUT ==
// 1
