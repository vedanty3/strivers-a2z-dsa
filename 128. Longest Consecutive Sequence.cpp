class Solution {
	public:
		int longestConsecutive(vector<int>& nums) {
			int n = nums.size();

			if (n == 0) {
				return 0;
			}

			int max_len = 1;
			unordered_set<int> st;

			for (int i = 0; i < n; ++i) {
				st.insert(nums[i]);
			}

			for (auto num : st) {
				if (st.find(num - 1) == st.end()) {
					int curr_len = 1;
					int curr_num = num;
					while (st.find(curr_num+1) != st.end()) {
						++curr_num;
						++curr_len;
					}
					max_len = max(curr_len, max_len);
				}
			}

			return max_len;
		}
};
