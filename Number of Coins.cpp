class Solution {
	public:
		int minCoins(vector<int> &coins, int M, int V) {
			vector<vector<int>> dp(M + 1, vector<int>(V + 1, 0));

			for (int i = 1; i <= V; ++i) {
				dp[0][i] = 1e9;
			}

			for (int i = 1; i <= M; ++i) {
				for (int j = 1; j <= V; ++j) {
					dp[i][j] = dp[i - 1][j];  // Exclude the current coin

					if (coins[i - 1] <= j) {
						dp[i][j] = min(dp[i][j], 1 + dp[i][j - coins[i - 1]]);
					}
				}
			}

			return dp[M][V] == 1e9 ? -1 : dp[M][V];
		}
};


