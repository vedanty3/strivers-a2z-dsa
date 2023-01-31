// BRUTE FORCE
class Solution
{
public:
    int cntPaths(int i, int j, int m, int n)
    {
        if (i == (m - 1) and j == (n - 1))
            return 1;
        else if (i >= m or j >= n)
            return 0;
        else
            return cntPaths(i + 1, j, m, n) + cntPaths(i, j + 1, m, n);
    }

    int uniquePaths(int m, int n)
    {
        return cntPaths(0, 0, m, n);
    }
};

// BETTER APPROACH
class Solution
{
public:
    int cntPaths(int i, int j, int m, int n, vector<vector<int>> &dp)
    {
        if (i == (m - 1) and j == (n - 1))
            return 1;
        if (i >= m or j >= n)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        return dp[i][j] = cntPaths(i + 1, j, m, n, dp) + cntPaths(i, j + 1, m, n, dp);
    }

    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return cntPaths(0, 0, m, n, dp);
    }
};