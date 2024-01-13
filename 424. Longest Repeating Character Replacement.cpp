class Solution {
	public:
		int characterReplacement(string s, int k) {
			int n = s.size();
			int max_len = 0;
			int i = 0;
			int j = 0;
			unordered_map<char, int>mpp;
			int max_repeating = 0;

			while(j<n) {
				mpp[s[j]]++;
				max_repeating = max(max_repeating, mpp[s[j]]);
				int nk = j - i + 1 - max_repeating;

				if(nk>k) {
					mpp[s[i]]--;
					++i;
				}

				max_len = max(max_len, j-i+1);
				++j;
			}

			return max_len;
		}
};
