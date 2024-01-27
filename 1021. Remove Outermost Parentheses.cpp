class Solution {
	public:
		string removeOuterParentheses(string s) {
			int n = s.size();
			int i = 0;
			int j = 0;
			int open = 0;
			string ans;

			while (j < n) {
				if (s[j] == '(') {
					++open;
				} else {
					--open;
					if (open == 0) {
						ans += s.substr(i + 1, j - i - 1);
						i = j+1;
					}
				}
				++j;
			}

			return ans;
		}
};
