int findMaxFruits(vector<int> &fruits, int n) {
	int i = 0;
	int j = 0;
	int ans = 0;
	unordered_map<int, int>m;

	while(j<n) {
		m[fruits[j]]++;

		while(m.size()>2) {
			m[fruits[i]]--;
			if(m[fruits[i]]==0) {
				m.erase(fruits[i]);
			}
			++i;
		}

		ans = max(ans, j-i+1);
		++j;
	}

	return ans;
}
