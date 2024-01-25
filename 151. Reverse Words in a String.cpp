class Solution {
	public:
		string reverseWords(string s) {
			int n = s.size();
			string ans, word;

			for(int i=0; i<n; ++i) {
				if(s[i]!=' ') {
					word.push_back(s[i]);
				} else {
					if(ans.size()>0 and word.size()>0) {
						ans = word + " " + ans;

					} else if(word.size()) {
						ans = word;
					}

					word = "";

				}
			}

			if(ans.size() and word.size()) {
				ans = word + " " + ans;
			} else if(word.size()) {
				ans = word;
			}

			return ans;
		}
};
