class Solution {
	public:
		int jump(vector<int>& nums) {
			int n = nums.size();
			int last_indx = 0;
			int total_jumps = 0;
			int window_size = 0;
			int destination = n-1;

			if(n==1) {
				return 0;
			}

			for(int i=0; i<n; ++i) {
				window_size = max(window_size, nums[i] + i);

				if(i==last_indx) {
					last_indx = window_size;
					++total_jumps;

					if(last_indx>=destination) {
						return total_jumps;
					}
				}
			}

			return total_jumps;
		}
};
