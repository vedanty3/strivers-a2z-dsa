class Solution {
	public:
		int numberOfSubstrings(string s) {
			int n = s.size();
			int i = 0;
			int j = 0;
			int ans = 0;
			unordered_map<char, int>mpp;

			while(j<n) {
				mpp[s[j]]++;
				while(mpp['a']>0 and mpp['b']>0 and mpp['c']>0) {
					mpp[s[i]]--;
					ans += n - j;
					++i;
				}

				++j;
			}

			return ans;
		}
};
