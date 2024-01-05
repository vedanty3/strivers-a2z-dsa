class Solution {
	public:
		int coinChange(vector<int>& coins, int amount) {
			int n = coins.size();
			vector<int>next(amount+1, 1e9);
			vector<int>curr(amount+1, 1e9);

			for(int i=0; i<n+1; ++i) {
				curr[0] = 0;
			}

			for(int i=n-1; i>=0; --i) {
				for(int j=1; j<=amount; ++j) {
					if(j>=coins[i]) {
						curr[j] = min(next[j], 1 + curr[j-coins[i]]);
					} else {
						curr[j] = next[j];
					}
				}
				next = curr;
			}

			return next[amount]==1e9 ? -1 : next[amount];
		}
};
