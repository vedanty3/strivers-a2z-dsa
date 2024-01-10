class Solution {
	public:
		string reverseWords(string s) {
			string ans, temp;
			int i = 0;
			int n = s.size();

			while (i < n) {
				if (s[i] == ' ') {
					if (ans.size() == 0 and temp.size()) {
						ans = temp + ans;
					} else if (temp.size()) {
						ans = temp + " " + ans;
					}
					temp = "";
				} else {
					temp.push_back(s[i]);
				}
				++i;
			}

			if (temp.size() and ans.size()) {
				ans = temp + " " + ans;
			} else {
				ans = temp + ans;
			}

			return ans;
		}
};
