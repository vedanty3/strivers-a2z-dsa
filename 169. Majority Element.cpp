class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int major = nums[0];
        int major_cnt = 1;

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == major) {
                ++major_cnt;
            } else {
                --major_cnt;
                if (major_cnt == 0) {
                    major = nums[i];
                    major_cnt = 1;
                }
            }
        }

        return major;
    }
};
