class Solution {
	public:
		int maxProduct(vector<int>& nums) {
			int res = INT_MIN;
			int curr_max = 1;
			int curr_min = 1;

			for(int i=0; i<nums.size(); ++i) {
				int temp = curr_max*nums[i];
				curr_max = max(curr_max*nums[i], max(curr_min*nums[i], nums[i]));
				curr_min = min(temp, min(curr_min*nums[i], nums[i]));
				res = max(res, curr_max);
			}

			return res;
		}
};
