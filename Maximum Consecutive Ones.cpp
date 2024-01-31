#include<bits/stdc++.h>

int longestSubSeg(vector<int> &nums , int n, int k) {
	int i = 0;
	int j = 0;
	int ans = 0;
	unordered_map<int, int>m;

	while(j<n) {
		m[nums[j]]++;

		while(m[0]>k) {
			m[nums[i]]--;
			++i;
		}

		ans = max(ans, j-i+1);
		++j;
	}

	return ans;
}

