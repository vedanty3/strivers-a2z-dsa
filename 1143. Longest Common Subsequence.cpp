class Solution {
	public:
		int longestCommonSubsequence(string text1, string text2) {
			int m = text1.size();
			int n = text2.size();
			int k = max(n, m) + 1;
			vector<int>next(k, 0);
			vector<int>curr(k, 0);

			for(int i=m-1; i>=0; --i) {
				for(int j=n-1; j>=0; --j) {
					int max_length = INT_MIN;
					if(text1[i]==text2[j]) {
						max_length = 1 + next[j+1];
					} else {
						max_length = max(next[j], curr[j+1]);
					}
					curr[j] = max_length;
				}
				next = curr;
			}

			return next[0];
		}
};
