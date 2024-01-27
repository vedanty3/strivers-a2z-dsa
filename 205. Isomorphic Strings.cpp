class Solution {
	public:
		bool isIsomorphic(string s, string t) {
			if(s.size()!=t.size()) {
				return false;
			}

			int n = s.size();
			unordered_map<char, char>m;

			for(int i=0; i<n; ++i) {
				if(!m.count(s[i])) {
					for(auto p : m) {
						if(p.second==t[i]) {
							return false;
						}
					}

					m[s[i]] = t[i];
				} else {
					if(m[s[i]]!=t[i]) {
						return false;
					}
				}
			}

			return true;
		}
};
