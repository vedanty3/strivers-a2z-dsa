class Solution {
	public:
		bool canJump(vector<int>& nums) {
			int n = nums.size();
			int final_indx = n-1;

			for(int i=n-1; i>=0; --i) {
				if(i + nums[i]>=final_indx) {
					final_indx = i;
				}
			}

			return final_indx==0;
		}
};
