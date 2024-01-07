class Solution {
	public:
		vector<int> majorityElement(vector<int>& nums) {
			int major1 = -1;
			int major2 = -1;
			int ct1 = 0;
			int ct2 = 0;

			for (int i = 0; i < nums.size(); ++i) {
				if (nums[i] == major1) {
					++ct1;
				} else if (nums[i] == major2) {
					++ct2;
				} else if (ct1 == 0) {
					major1 = nums[i];
					ct1 = 1;
				} else if (ct2 == 0) {
					major2 = nums[i];
					ct2 = 1;
				} else {
					--ct1;
					--ct2;
				}
			}

			ct1 = 0;
			ct2 = 0;
			vector<int> ans;

			for (int i = 0; i < nums.size(); ++i) {
				if (nums[i] == major1) {
					++ct1;
				} else if (nums[i] == major2) {
					++ct2;
				}
			}

			if (ct1 > nums.size() / 3) {
				ans.push_back(major1);
			}

			if (ct2 > nums.size() / 3) {
				ans.push_back(major2);
			}

			return ans;
		}
};

