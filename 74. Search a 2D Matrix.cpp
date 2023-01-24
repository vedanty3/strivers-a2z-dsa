// BRUTE FORCE
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        for (int i = 0; i < matrix.size(); ++i)
        {
            bool is_there = binary_search(matrix[i].begin(), matrix[i].end(), target);
            if (is_there)
                return is_there;
        }
        return false;
    }
};

// BETTER
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int i = 0, j = matrix[0].size() - 1;
        while (i < matrix.size() and j >= 0)
        {
            if (matrix[i][j] == target)
            {
                return true;
            }
            else if (matrix[i][j] < target)
            {
                i++;
            }
            else
            {
                j--;
            }
        }

        return false;
    }
};

// Optimal
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size(), n = matrix[0].size();
        int low = 0, high = m * n - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (matrix[mid / n][mid % n] == target)
                return true;
            else if (matrix[mid / n][mid % n] > target)
                high = mid - 1;
            else
                low = mid + 1;
        }

        return false;
    }
};