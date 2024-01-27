#include<bits/stdc++.h>

pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x) {
	if(binary_search(a.begin(), a.end(), x)) {
		return {x, x};
	}

	int indx = lower_bound(a.begin(), a.end(), x) - a.begin();
	int floor_of_x =  indx > 0 ? a[indx-1] : -1;
	int ceil_of_x = *upper_bound(a.begin(), a.end(), x);

	if(ceil_of_x<x) {
		ceil_of_x = -1;
	}

	return {floor_of_x, ceil_of_x};
}
