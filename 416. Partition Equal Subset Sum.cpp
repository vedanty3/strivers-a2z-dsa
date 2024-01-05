class Solution {
	public:
		bool canPartition(vector<int>& nums) {
			int sum = 0;
			int n = nums.size();

			for(int i=0; i<nums.size(); ++i) {
				sum += nums[i];
			}

			if(sum&1) {
				return false;
			} else {
				vector<bool>next(sum/2+1, false);
				vector<bool>curr(sum/2+1, false);

				curr[0] = true;
				next[0] = true;

				for(int i=n-1; i>=0; --i) {
					for(int j=1; j<=sum/2; ++j) {
						curr[j] = next[j];
						if(j>=nums[i]) {
							curr[j] = curr[j] || next[j-nums[i]];
						}
					}
					next = curr;
				}

				return next[sum/2];
			}
		}
};
