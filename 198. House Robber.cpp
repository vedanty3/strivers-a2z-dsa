class Solution {
	public:
		int rob(vector<int>& nums) {
			int n = nums.size();
			vector<int>dp(n+1, 0);

			dp[1] = nums[0];

			for(int i=2; i<=n; ++i) {
				int max_money = -1e9;
				max_money = max(max_money, dp[i-1]);
				max_money = max(max_money, nums[i-1] + dp[i-2]);
				dp[i] = max_money;
			}

			return dp[n];
		}
};
