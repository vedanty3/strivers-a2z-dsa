class Solution
{
public:
    int cntCrossReversePairs(vector<int> &nums, int s, int e)
    {
        int i = s;
        int mid = s + (e - s) / 2;
        int j = mid + 1;
        int k = 0;
        int cnt = 0;
        vector<int> tmp;

        for (i; i <= mid; ++i)
        {
            while (j <= e and nums[i] > (nums[j] * 2LL))
            {
                ++j;
            }
            cnt += j - mid - 1;
        }

        i = s;
        j = mid + 1;

        while (i <= mid and j <= e)
        {
            if (nums[i] <= nums[j])
            {
                tmp.emplace_back(nums[i]);
                i++;
            }
            else
            {
                tmp.emplace_back(nums[j]);
                j++;
            }
        }

        while (i <= mid)
        {
            tmp.emplace_back(nums[i]);
            i++;
        }

        while (j <= e)
        {
            tmp.emplace_back(nums[j]);
            j++;
        }

        for (int i = s; i <= e; ++i)
        {
            nums[i] = tmp[k++];
        }

        return cnt;
    }

    int cntReversePairs(vector<int> &nums, int s, int e)
    {
        if (s >= e)
            return 0;
        int mid = s + (e - s) / 2;
        int rev_pairs = cntReversePairs(nums, s, mid);
        rev_pairs += cntReversePairs(nums, mid + 1, e);
        rev_pairs += cntCrossReversePairs(nums, s, e);
        return rev_pairs;
    }

    int reversePairs(vector<int> &nums)
    {
        return cntReversePairs(nums, 0, nums.size() - 1);
    }
};