// BRUTE FORCE
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int ans = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = 0; j < nums.size(); ++j)
            {
                if (nums[i] == nums[j] and i != j)
                {
                    ans = nums[i];
                    break;
                }
            }
        }
        return ans;
    }
};

// HASHING
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        map<int, int> mpp;
        for (auto it : nums)
        {
            mpp[it]++;
            if (mpp[it] > 1)
                return it;
        }

        return 0;
    }
};

// Tortoise Method
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int slo = nums[0], fast = nums[0];

        do
        {
            slo = nums[slo];
            fast = nums[nums[fast]];
        } while (slo != fast);

        slo = nums[0];

        while (slo != fast)
        {
            slo = nums[slo];
            fast = nums[fast];
        }

        return slo;
    }
};