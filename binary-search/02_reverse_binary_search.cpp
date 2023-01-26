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
    int reverseBinarySearch(const vector<int> &arr, const int search) {
        int start = 0;
        int end = arr.size() - 1;

        while(start <= end) {
            int mid = start + (end - start) / 2;
            
            if(arr[mid] == search) {
                return mid;
            } else if(search > arr[mid]) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return -1;
    }
};

int main() {
	stayTORO();

    int n;
    cin>>n;

    vector<int> arr(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int search;
    cin >> search;

    Solution S;

    cout << S.reverseBinarySearch(arr, search);

    return 0;
}

// == IN ==
// 6
// 6 5 4 3 2 1
// 4

// == OUT ==
// 2
