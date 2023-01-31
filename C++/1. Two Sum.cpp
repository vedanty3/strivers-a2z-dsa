// BRUTE FORCE
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        for (int i = 0; i < nums.size(); ++i)
        {
            int rem = target - nums[i];
            for (int j = 0; j < nums.size(); ++j)
            {
                if (j == i)
                    continue;
                if (rem == nums[j])
                {
                    return {i, j};
                }
            }
        }

        return {};
    }
};

// Optimal
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        map<int, int> mpp;

        for (int i = 0; i < nums.size(); ++i)
        {
            int rem = target - nums[i];
            if (mpp.find(rem) != mpp.end())
            {
                return {i, mpp[rem]};
            }
            mpp[nums[i]] = i;
        }

        return {};
    }
};