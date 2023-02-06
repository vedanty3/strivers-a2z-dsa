class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        int max_seq = 0;
        unordered_set<int> st;
        for (auto num : nums)
        {
            st.insert(num);
        }

        for (int i = 0; i < nums.size(); ++i)
        {
            if (st.find(nums[i] - 1) == st.end())
            {
                int cnt = 1, curr_num = nums[i] + 1;
                while (true)
                {
                    if (st.find(curr_num) != st.end())
                    {
                        ++cnt, ++curr_num;
                    }
                    else
                    {
                        break;
                    }
                }
                max_seq = max(cnt, max_seq);
            }
        }

        return max_seq;
    }
};