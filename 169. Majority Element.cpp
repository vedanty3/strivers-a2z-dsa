class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int major = nums[0];
        int cnt = 1;
        for (int i = 1; i < nums.size(); ++i)
        {
            if (major == nums[i])
                cnt++;
            else if (major != nums[i])
                cnt--;
            if (cnt == 0)
            {
                major = nums[i];
                cnt = 1;
            }
        }

        return major;
    }
};