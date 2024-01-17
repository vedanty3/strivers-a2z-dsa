vector<int>rabin_karp(string&text, string&pattern) {
	const int p = 31;
	const int N = 1e9 + 7;
	int m = text.size();
	int n = pattern.size();

	vector<long long>powers(max(m, n));
	powers[0] = 1;

	for(int i=1; i<powers.size(); ++i) {
		powers[i] = (powers[i-1] * p) % N;
	}

	vector<long long>text_hash(m+1, 0);
	for(int i=0; i<m; ++i) {
		text_hash[i+1] = (text_hash[i] + ((text[i]-'a' + 1) * powers[i]))%N;
	}

	long long int pattern_hash = 0;
	for(int i=0; i<n; ++i) {
		pattern_hash = (pattern_hash + (powers[i] * (pattern[i]-'a' + 1)))%N;
	}

	vector<int>found_indices;
	for(int i=0; i<m-n+1; ++i) {
		int curr_hash = (text_hash[i+n] + N - text_hash[i])%N;
		if(curr_hash==pattern_hash*powers[i]%N) {
			found_indices.push_back(i);
		}
	}

	return found_indices;
}

int firstOccurence(string &text, string &pat) {
	vector<int>ans = rabin_karp(text, pat);
	return ans.size()==0 ? -1 : ans[0];
}
