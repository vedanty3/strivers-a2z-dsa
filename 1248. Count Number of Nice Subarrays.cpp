class Solution {
	public:
		int solve(vector<int>& nums, int k) {
			int n = nums.size();
			int ans = 0;
			int odd_k = 0;
			int i = 0;
			int j = 0;
			while (j < n) {
				if (nums[j] & 1) {
					++odd_k;
				}
				while (odd_k > k) {
					if (nums[i] & 1) {
						--odd_k;
					}
					++i;
				}
				ans += j - i + 1;
				++j;
			}
			return ans;
		}

		int numberOfSubarrays(vector<int>& nums, int k) {
			return solve(nums, k) - solve(nums, k-1);
		}
};
