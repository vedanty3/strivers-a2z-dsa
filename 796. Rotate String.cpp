class Solution {
	private:
		const int N = 1e9 + 7;
		bool karp_rabin(string& text, string& pattern) {
			int m = text.size();
			int n = pattern.size();
			int p = 31;
			vector<long long> powers(max(m, n));
			powers[0] = 1;

			for(int i=1; i<powers.size(); ++i) {
				powers[i] = (powers[i-1]*p)%N;
			}

			vector<long long>text_hash(m+1, 0);

			for(int i=0; i<m; ++i) {
				text_hash[i+1] = (text_hash[i] + powers[i] * (text[i]-'a'+1))%N;
			}

			long long int pattern_hash = 0;

			for(int i=0; i<n; ++i) {
				pattern_hash = (pattern_hash + powers[i] * (pattern[i]-'a'+1))%N;
			}

			for(int i=0; i<m-n+1; ++i) {
				long long curr_hash = (text_hash[i+n] - text_hash[i] + N)%N;
				if(curr_hash==(powers[i]*pattern_hash)%N) {
					return true;
				}
			}

			return false;
		}

	public:
		bool rotateString(string s, string goal) {
			if(s.size()!=goal.size()) {
				return false;
			}
			string text = s + s;
			string pattern = goal;
			return karp_rabin(text, pattern);
		}
};
