class Solution {
	public:
		int maxLen(vector<int>&nums, int n) {
			int max_len = 0;
			int curr_sum = 0;
			unordered_map<int, int>mpp;

			for(int i=0; i<n; ++i) {
				curr_sum += nums[i];
				if(curr_sum==0) {
					max_len = max(max_len, i+1);
				} else {
					if(mpp.count(curr_sum)) {
						max_len = max(max_len, i-mpp[curr_sum]);
					} else {
						mpp[curr_sum] = i;
					}
				}
			}

			return max_len;
		}
};
