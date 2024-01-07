class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int lo = 0;
        int hi = m*n-1;

        while(lo<=hi) {
            int mid = lo + (hi-lo)/2;
            int ro = mid/n;
            int col = mid%n;
            if(matrix[ro][col]==target) {
                return true;
            } else if(matrix[ro][col]<target) {
                lo = mid+1;
            } else {
                hi = mid-1;
            }
        }

        return false;
    }
};

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int j = n-1;
        int i = 0;

        while(i<m and j>=0) {
            if(target<matrix[i][j]) {
                --j;
            } else if(target>matrix[i][j]) {
                ++i;
            } else {
                return true;
            }
        }

        return false;
    }
};
