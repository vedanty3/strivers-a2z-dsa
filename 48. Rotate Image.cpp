// Approach 1

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>>new_matrix(n, vector<int>(n, 0));
        
        for(int i=0; i<n; ++i) {
            for(int j=0; j<n; ++j) {
                new_matrix[j][n-i-1] = matrix[i][j];
            }
        }
        
        matrix = new_matrix;
        
    }
};

// Approach 2

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        for(int i=0; i<m; ++i) {
            for(int j=0; j<i; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        for(auto &ro : matrix) {
            reverse(ro.begin(), ro.end());
        }
    }
};
