#include<bits/stdc++.h>

int kDistinctChars(int k, string &s) {
	int n = s.size();
	int i = 0;
	int j = 0;
	int max_len = 0;
	unordered_map<char, int>m;

	while(j<n) {
		m[s[j]]++;

		while(m.size()>k) {
			m[s[i]]--;
			if(m[s[i]]==0) {
				m.erase(s[i]);
			}
			++i;
		}
		max_len = max(max_len, j-i+1);
		++j;
	}

	return max_len;
}



