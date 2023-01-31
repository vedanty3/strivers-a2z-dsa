// TC: O(N^2)
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int mini = INT_MAX;
        int max_profit = INT_MIN;

        for (int i = 0; i < prices.size() - 1; ++i)
        {
            mini = prices[i];
            for (int j = i + 1; j < prices.size(); ++j)
            {
                max_profit = max(max_profit, prices[j] - mini);
            }
        }

        return max_profit < 0 ? 0 : max_profit;
    }
};

// TC: O(N)
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int mini = INT_MAX;
        int max_profit = INT_MIN;

        for (int i = 0; i < prices.size(); ++i)
        {
            mini = min(mini, prices[i]);
            max_profit = max(max_profit, prices[i] - mini);
        }

        return max_profit;
    }
};