class Solution {
	public:
		bool isAnagram(string s, string t) {
			if (s.size() != t.size()) {
				return false;
			}

			unordered_map<char, int> m1, m2;

			for (auto ch : s) {
				m1[ch]++;
			}

			for (auto ch : t) {
				m2[ch]++;
			}

			for (auto p : m1) {
				if (!m2.count(p.first) or m2[p.first] != p.second) {
					return false;
				}
			}

			return true;
		}
};
