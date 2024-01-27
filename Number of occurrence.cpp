#include<bits/stdc++.h>

int count(vector<int>& arr, int n, int x) {
	if(!binary_search(arr.begin(), arr.end(), x)) {
		return 0;
	}

	int lo = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
	int hi = upper_bound(arr.begin(), arr.end(), x) - arr.begin() - 1;
	return hi - lo + 1;
}

