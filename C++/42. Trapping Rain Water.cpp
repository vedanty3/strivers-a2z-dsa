// TC: O(3N) ~ O(N)
// SC: O(2N) ~ O(N)
class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        int max_val = INT_MIN;
        vector<int> prefix(n);
        vector<int> suffix(n);

        for (int i = 0; i < n; ++i)
        {
            max_val = max(max_val, height[i]);
            prefix[i] = max_val;
        }

        max_val = INT_MIN;

        for (int i = n - 1; i >= 0; --i)
        {
            max_val = max(max_val, height[i]);
            suffix[i] = max_val;
        }

        int water_cnt = 0;

        for (int i = 0; i < n; ++i)
        {
            int curr_max = min(prefix[i], suffix[i]) - height[i];
            water_cnt += curr_max;
        }

        return water_cnt;
    }
};

// TC: O(N)
// SC: O(1)
class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        int left_max = 0;
        int right_max = 0;
        int res = 0;
        int left = 0;
        int right = n - 1;

        while (left <= right)
        {
            if (height[left] <= height[right])
            {
                if (height[left] >= left_max)
                {
                    left_max = height[left];
                }
                else
                {
                    res += left_max - height[left];
                }
                ++left;
            }
            else
            {
                if (height[right] >= right_max)
                {
                    right_max = height[right];
                }
                else
                {
                    res += right_max - height[right];
                }
                --right;
            }
        }

        return res;
    }
};