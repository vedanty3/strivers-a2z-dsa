class Solution {
	public:
		int findDuplicate(vector<int>& nums) {
			int slo = nums[0];
			int fast = nums[0];

			do {
				slo = nums[slo];
				fast = nums[nums[fast]];
			} while(slo!=fast);

			fast = nums[0];

			while(slo!=fast) {
				slo = nums[slo];
				fast = nums[fast];
			}

			return slo;
		}
};
