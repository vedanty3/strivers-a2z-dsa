class Solution {
	public:
		int search(vector<int>& nums, int target) {
			int n = nums.size();
			int lo = 0;
			int hi = n-1;

			while(lo<=hi) {
				int mid = lo + (hi-lo)/2;
				if(nums[mid]==target) {
					return mid;
				} else if(nums[mid]>=nums[lo]) {
					if(nums[lo]<=target and target<=nums[mid]) {
						hi = mid - 1;
					} else {
						lo = mid + 1;
					}
				} else if(nums[mid]<=nums[hi]) {
					if(nums[mid]<=target and nums[hi]>=target) {
						lo = mid + 1;
					} else {
						hi = mid - 1;
					}
				}
			}

			return -1;
		}
};
