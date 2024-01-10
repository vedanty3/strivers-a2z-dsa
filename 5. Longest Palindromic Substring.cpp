class Solution {
	public:
		string longestPalindrome(string str) {
			int n = str.size();
			if (n <= 1) {
				return str;
			}
			int max_len = 0;
			int l, r;

			for (int i = 0; i < n - 1; ++i) {
				int s = i;
				int e = i;

				while (s >= 0 and e < n) {
					if (str[s] == str[e]) {
						--s;
						++e;
					} else {
						break;
					}
				}

				if (max_len < e - s - 1) {
					max_len = e - s - 1;
					l = s + 1;
					r = e - 1;
				}
			}

			for (int i = 0; i < n - 1; ++i) {
				int s = i;
				int e = i + 1;

				while (s >= 0 and e < n) {
					if (str[s] == str[e]) {
						--s;
						++e;
					} else {
						break;
					}
				}

				if (max_len < e - s - 1) {
					max_len = e - s - 1;
					l = s + 1;
					r = e - 1;
				}
			}

			return str.substr(l, max_len);
		}
};
