class Solution {
	public:
		int lengthOfLongestSubstring(string s) {
			int n = s.size();
			int i = 0;
			int j = 0;
			int max_len = 0;
			unordered_map<int, int>mpp;

			while (j < n) {
				if (mpp.find(s[j]) != mpp.end() and i<=mpp[s[j]]) {
					i = mpp[s[j]] + 1;
				}
				mpp[s[j]] = j;
				max_len = max(max_len, j - i + 1);
				++j;
			}

			return max_len;
		}
};
