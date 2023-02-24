class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i)
        {
            int lo = i + 1, hi = nums.size() - 1, rem = 0 - nums[i];
            while (lo < hi)
            {
                int gained = nums[lo] + nums[hi];
                if (gained < rem)
                {
                    ++lo;
                }
                else if (gained > rem)
                {
                    --hi;
                }
                else
                {
                    ans.push_back({nums[i], nums[lo], nums[hi]});
                    while (lo < hi and nums[lo] == nums[lo + 1])
                    {
                        ++lo;
                    }
                    while (lo < hi and nums[hi] == nums[hi - 1])
                    {
                        --hi;
                    }
                    ++lo, --hi;
                }
            }
            while (i + 1 < nums.size() and nums[i] == nums[i + 1])
            {
                ++i;
            }
        }

        return ans;
    }
};