// TC: O(NLogN)
class Solution
{
public:
    int partition(vector<int> &nums, int s, int e)
    {
        int p = nums[e];
        int i = s - 1;

        for (int j = s; j < e; ++j)
        {
            if (nums[j] < p)
            {
                i++;
                swap(nums[i], nums[j]);
            }
        }

        swap(nums[i + 1], nums[e]);
        return i + 1;
    }

    void quickSort(vector<int> &nums, int s, int e)
    {
        if (s >= e)
            return;
        int p = partition(nums, s, e);
        quickSort(nums, s, p - 1);
        quickSort(nums, p + 1, e);
    }

    void sortColors(vector<int> &nums)
    {
        quickSort(nums, 0, nums.size() - 1);
    }
};

// TC: O(N)
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int lo = 0;
        int mid = 0;
        int hi = nums.size() - 1;

        while (mid <= hi)
        {
            if (nums[mid] == 0)
            {
                swap(nums[mid], nums[lo]);
                lo++, mid++;
            }
            else if (nums[mid] == 1)
            {
                mid++;
            }
            else
            {
                swap(nums[mid], nums[hi]);
                --hi;
            }
        }
    }
};