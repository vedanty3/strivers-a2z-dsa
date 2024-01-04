class Solution {
	public:
		int matrixMultiplication(int N, int arr[]) {
			vector<vector<int>>dp(N, vector<int>(N, 0));
			for (int i = 1; i < N; i++) {
				dp[i][i] = 0;
			}
			for(int i=N-1; i>=1; --i) {
				for(int j=i+1; j<N; ++j) {
					dp[i][j] = 1e9;
					for(int k=i; k<j; ++k) {
						dp[i][j]  = min(dp[i][j] , dp[i][k] + dp[k+1][j] + arr[i-1] * arr[k] * arr[j]);
					}

				}
			}

			return dp[1][N-1];
		}
};
