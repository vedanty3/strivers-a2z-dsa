class Solution {
	public:
		bool rabin_karp(string& text, string& pattern) {
			int p = 27;
			int N = 1e9 + 7;
			int m = text.size();
			int n = pattern.size();

			vector<long long> powers(max(m, n));
			powers[0] = 1;

			for (int i = 1; i < max(m, n); ++i) {
				powers[i] = (p * powers[i - 1]) % N;
			}

			vector<long long> text_hash(m + 1, 0);

			for (int i = 0; i < m; ++i) {
				text_hash[i + 1] =
				  (text_hash[i] + ((text[i] - 'a' + 1) * powers[i])) % N;
			}

			long long int pattern_hash = 0;

			for (int i = 0; i < n; ++i) {
				pattern_hash =
				  (pattern_hash + ((pattern[i] - 'a' + 1) * powers[i])) % N;
			}

			for (int i = 0; i < m - n + 1; ++i) {
				int curr_hash = (text_hash[i + n] + N - text_hash[i]) % N;
				if (curr_hash == powers[i] * pattern_hash % N) {
					return true;
				}
			}
			return false;
		}
		int repeatedStringMatch(string a, string b) {
			string temp;
			int min_repeat = 0;
			while (temp.size() < b.size()) {
				temp += a;
				min_repeat++;
			}
			if (rabin_karp(temp, b)) {
				return min_repeat;
			}
			min_repeat++;
			temp += a;
			if (rabin_karp(temp, b)) {
				return min_repeat;
			}
			return -1;
		}
};
