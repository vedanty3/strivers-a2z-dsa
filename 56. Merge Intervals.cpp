class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        int start_i = intervals[0][0];
        int end_i = intervals[0][1];

        for (int i = 1; i < intervals.size(); ++i)
        {
            if (end_i < intervals[i][0])
            {
                ans.push_back({start_i, end_i});
                start_i = intervals[i][0];
                end_i = intervals[i][1];
            }
            else
            {
                end_i = max(end_i, intervals[i][1]);
            }
        }
        ans.push_back({start_i, end_i});
        return ans;
    }
};