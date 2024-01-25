class Solution {
	public:
		string longestCommonPrefix(vector<string>& strs) {
			string ans;
			sort(strs.begin(), strs.end());
			int n = strs.size();
			string t = strs[0];
			string s = strs[n-1];

			for(int i=0; i<min(t.size(), s.size()); ++i) {
				if(t[i]==s[i]) {
					ans.push_back(s[i]);
				} else {
					break;
				}
			}

			return ans;
		}
};
