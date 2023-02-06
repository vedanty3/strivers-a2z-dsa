// TC: O(2*N)
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        if (!s.size())
        {
            return 0;
        }
        int max_len = INT_MIN;
        unordered_set<int> st;
        int lo = 0, hi = 0;

        while (hi < s.size())
        {
            if (st.find(s[hi]) != st.end())
            {
                while (lo < hi and st.find(s[hi]) != st.end())
                {
                    st.erase(s[lo]);
                    ++lo;
                }
            }
            st.insert(s[hi]);
            max_len = max(max_len, hi - lo + 1);
            ++hi;
        }

        return max_len;
    }
};

// TC: O(N)
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        if (!s.size())
        {
            return 0;
        }
        unordered_map<char, int> mpp;
        int lo = 0, hi = 0, max_len = INT_MIN;

        while (hi < s.size())
        {
            if (mpp.find(s[hi]) != mpp.end())
            {
                lo = max(lo, mpp[s[hi]] + 1);
            }

            mpp[s[hi]] = hi;
            max_len = max(max_len, hi - lo + 1);
            ++hi;
        }

        return max_len;
    }
};