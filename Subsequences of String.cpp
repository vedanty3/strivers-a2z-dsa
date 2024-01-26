#include <bits/stdc++.h>

vector<string> subsequences(string s) {
	int n = s.size();
	vector<string>ans;

	for(int i=0; i<(1<<n); ++i) {
		int num = i;
		int j = 0;
		string subsequence;
		while(num) {
			if(num&1) {
				subsequence.push_back(s[j]);
			}
			num >>= 1;
			++j;
		}
		if(subsequence.size()) {
			ans.push_back(subsequence);
		}
	}

	return ans;
}

