class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int break_pt = -1;

        for (int i = n - 1; i >= 1; --i) {
            if (nums[i - 1] < nums[i]) {
                break_pt = i - 1;
                break;
            }
        }

        if (break_pt == -1) {
            reverse(nums.begin(), nums.end());
        } else {

            for (int i = n - 1; i >= break_pt; --i) {
                if (nums[break_pt] < nums[i]) {
                    swap(nums[break_pt], nums[i]);
                    break;
                }
            }

            reverse(nums.begin() + break_pt + 1, nums.end());
        }
    }
};
