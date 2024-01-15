class Solution {
	public:
		string minWindow(string s, string t) {
			int m = s.size();
			int i = 0;
			int j = 0;
			int min_len = INT_MAX;
			int ans = -1;
			unordered_map<char, int> m1, m2;
			int k = 0;
			for (auto ch : t) {
				m2[ch]++;
			}
			int n = m2.size();
			while (j < m) {
				if (m2.count(s[j])) {
					m1[s[j]]++;
					if (m1[s[j]] == m2[s[j]]) {
						++k;
					}
				}
				while (k == n) {
					if (j - i + 1 <= min_len) {
						min_len = j - i + 1;
						ans = i;
					}
					if (m1.count(s[i])) {
						m1[s[i]]--;
						if (m2[s[i]] > m1[s[i]]) {
							--k;
						}
					}
					++i;
				}
				++j;
			}
			return ans == -1 ? "" : s.substr(ans, min_len);
		}
};
