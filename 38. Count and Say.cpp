class Solution {
	public:
		string solve(int n) {
			if (n == 1) {
				return "1";
			}

			string s = solve(n - 1);

			string t;
			int cnt = 1;

			for (int i = 1; i < s.size(); ++i) {
				if (s[i] == s[i - 1]) {
					++cnt;
				} else {
					t += to_string(cnt) + s[i - 1];
					cnt = 1;
				}
			}

			return t + to_string(cnt) + s[s.size() - 1];
		}
		string countAndSay(int n) {
			return solve(n);
		}
};
