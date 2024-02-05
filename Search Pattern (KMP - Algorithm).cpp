vector<int>kmp(string&text, string&pattern) {
	string s = pattern + "#" + text;
	int n = s.size();
	vector<int>lps(n, 0);

	for(int i=1; i<n; ++i) {
		int j = lps[i-1];
		while(j>0 and s[j]!=s[i]) {
			j = lps[j-1];
		}
		if(s[i]==s[j]) {
			++j;
		}
		lps[i] = j;
	}

	return lps;
}

vector<int> stringMatch(string text, string pattern) {
	int n = text.size();
	int m = pattern.size();
	vector<int>ans;
	vector<int>lps = kmp(text, pattern);

	for(int i=0; i<lps.size(); ++i) {
		if(lps[i]==m) {
			ans.push_back(i-2*pattern.size()+1);
		}
	}

	return ans;
}
