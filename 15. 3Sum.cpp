class Solution {
	public:
		vector<vector<int>> threeSum(vector<int>& nums) {
			int n = nums.size();
			vector<vector<int>> ans;

			sort(nums.begin(), nums.end());

			for (int i = 0; i < n; ++i) {
				int lo = i + 1;
				int hi = n - 1;

				while (lo < hi) {
					int sum = nums[i] + nums[lo] + nums[hi];
					if (sum == 0) {
						ans.push_back({nums[i], nums[lo], nums[hi]});
						while (lo < hi and nums[lo] == nums[lo + 1]) {
							++lo;
						}
						while (lo < hi and nums[hi] == nums[hi - 1]) {
							--hi;
						}
						++lo;
						--hi;
					} else if (sum < 0) {
						++lo;
					} else {
						--hi;
					}
				}
				while (i + 1 < n and nums[i] == nums[i + 1]) {
					++i;
				}
			}
			return ans;
		}
};
