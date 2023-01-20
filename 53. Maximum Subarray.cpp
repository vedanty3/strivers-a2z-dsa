// TC: O(N^3)
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int max_sum = nums[0];
        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = 0; j < nums.size(); ++j)
            {
                int sum = 0;
                for (int k = i; k <= j; ++k)
                {
                    sum += nums[k];
                }
                max_sum = max(max_sum, sum);
            }
        }

        return max_sum;
    }
};

// TC: O(N^2)
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int max_sum = INT_MIN;
        for (int i = 0; i < nums.size(); ++i)
        {
            int curr_sum = 0;
            for (int j = i; j < nums.size(); ++j)
            {
                curr_sum += nums[j];
                max_sum = max(max_sum, curr_sum);
            }
        }
        return max_sum;
    }
};

// TC: O(N)
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int max_sum = INT_MIN;
        int curr_sum = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            curr_sum += nums[i];
            max_sum = max(max_sum, curr_sum);
            if (curr_sum < 0)
                curr_sum = 0;
        }
        return max_sum;
    }
};