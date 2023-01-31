// BRUTE FORCE
class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        for (int i = 0; i < matrix.size(); ++i)
        {
            for (int j = 0; j < matrix[i].size(); ++j)
            {
                if (matrix[i][j] == 0)
                {
                    for (int x = 0; x < matrix.size(); ++x)
                    {
                        if (matrix[x][j] != 0)
                            matrix[x][j] = -99;
                    }

                    for (int x = 0; x < matrix[0].size(); ++x)
                    {
                        if (matrix[i][x] != 0)
                            matrix[i][x] = -99;
                    }
                }
            }
        }

        for (int i = 0; i < matrix.size(); ++i)
        {
            for (int j = 0; j < matrix[i].size(); ++j)
            {
                if (matrix[i][j] == -99)
                    matrix[i][j] = 0;
            }
        }
    }
};

// BETTER APPROACH
class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        vector<int> row_mat(matrix.size(), -1);
        vector<int> col_mat(matrix[0].size(), -1);

        for (int i = 0; i < matrix.size(); ++i)
        {
            for (int j = 0; j < matrix[0].size(); ++j)
            {
                if (matrix[i][j] == 0)
                {
                    row_mat[i] = 0;
                    col_mat[j] = 0;
                }
            }
        }

        for (int i = 0; i < matrix.size(); ++i)
        {
            for (int j = 0; j < matrix[0].size(); ++j)
            {
                if (row_mat[i] == 0 or col_mat[j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

// MOST OPTIMAL
class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int col = 1;
        for (int i = 0; i < matrix.size(); ++i)
        {
            if (matrix[i][0] == 0)
                col = 0;
            for (int j = 1; j < matrix[0].size(); ++j)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }

        for (int i = matrix.size() - 1; i >= 0; --i)
        {
            for (int j = matrix[0].size() - 1; j >= 1; --j)
            {
                if (matrix[i][0] == 0 or matrix[0][j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
            if (col == 0)
                matrix[i][0] = 0;
        }
    }
};