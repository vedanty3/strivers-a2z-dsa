class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int max_ones_cnt = 0;
        int curr_max_cnt = 0;
        int i = 0;
        int n = nums.size();

        while (i < n)
        {
            if (nums[i] == 1)
            {
                ++curr_max_cnt;
                max_ones_cnt = max(max_ones_cnt, curr_max_cnt);
            }
            else
            {
                curr_max_cnt = 0;
            }

            ++i;
        }

        return max_ones_cnt;
    }
};