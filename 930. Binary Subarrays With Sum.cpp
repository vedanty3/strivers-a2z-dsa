class Solution {
	public:
		int solve(vector<int>& nums, int goal) {
			if (goal < 0) {
				return 0;
			}
			int n = nums.size();
			int ans = 0;
			int i = 0;
			int j = 0;
			int sum = 0;
			while (j < n) {
				sum += nums[j];
				while (sum > goal) {
					sum -= nums[i];
					++i;
				}
				ans += j - i + 1;
				++j;
			}
			return ans;
		}
		int numSubarraysWithSum(vector<int>& nums, int goal) {
			return solve(nums, goal) - solve(nums, goal - 1);
		}
};
