class Solution {
	public:
		int characterReplacement(string s, int k) {
			int n = s.size();
			int i = 0;
			int j = 0;
			int r = 0;
			int max_len = 0;
			unordered_map<char, int> mpp;

			while (j < n) {
				mpp[s[j]]++;
				r = max(r, mpp[s[j]]);
				int nr = j - i + 1 - r;

				if (nr > k) {
					mpp[s[i]]--;
					++i;
				}

				max_len = max(max_len, j - i + 1);
				++j;
			}

			return max_len;
		}
};

