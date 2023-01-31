class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int major1 = -1, major2 = -1, cnt1 = 0, cnt2 = 0;
        vector<int> ans;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (major1 == nums[i])
            {
                cnt1++;
            }
            else if (major2 == nums[i])
            {
                cnt2++;
            }
            else if (cnt1 == 0)
            {
                major1 = nums[i];
                cnt1 = 1;
            }
            else if (cnt2 == 0)
            {
                major2 = nums[i];
                cnt2 = 1;
            }
            else
            {
                cnt1--, cnt2--;
            }
        }

        int n = nums.size() / 3;
        cnt1 = cnt2 = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] == major1)
                cnt1++;
            else if (nums[i] == major2)
                cnt2++;
        }

        if (cnt1 > n)
        {
            ans.emplace_back(major1);
        }
        if (cnt2 > n)
        {
            ans.emplace_back(major2);
        }

        return ans;
    }
};