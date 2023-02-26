class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int i = 0, j = 1, n = nums.size();

        while (j < n)
        {
            if (nums[i] == nums[j])
            {
                ++j;
            }
            else
            {
                ++i;
                nums[i] = nums[j];
            }
        }

        return i + 1;
    }
};