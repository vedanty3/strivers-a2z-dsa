class Solution {
	public:
		int minDistance(string s, string t) {
			int m = s.size();
			int n = t.size();

			if(s.size()==0) {
				return t.size();
			} else if(t.size()==0) {
				return s.size();
			}

			vector<int>next(n+1, 0);
			vector<int>curr(n+1, 0);

			for(int i=0; i<n; ++i) {
				next[i] = n-i;
			}

			for (int i = m-1; i >= 0; --i) {
				for (int j = n-1; j >= 0; --j) {
					curr[n] = m - i;
					int min_ops = 1e9;
					if (s[i] == t[j]) {
						min_ops = next[j + 1];
					} else {
						min_ops = min(1 + curr[j + 1], 1 + next[j]);
						min_ops = min(min_ops, 1 + next[j + 1]);
					}
					curr[j] = min_ops;
				}
				next = curr;
			}

			return next[0];
		}
};
