class Solution
{
public:
    int maxLen(vector<int> &A, int n)
    {
        int max_len = 0, curr_sum = 0;
        unordered_map<int, int> mpp;
        for (int i = 0; i < A.size(); ++i)
        {
            curr_sum += A[i];
            if (curr_sum == 0)
            {
                max_len = max(max_len, i + 1);
            }
            else
            {
                if (mpp.find(curr_sum) == mpp.end())
                {
                    mpp[curr_sum] = i;
                }
                else
                {
                    max_len = max(max_len, i - mpp[curr_sum]);
                }
            }
        }

        return max_len;
    }
};