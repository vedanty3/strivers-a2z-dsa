// Approach 1

class Solution
{
public:
    void solve(int indx, int curr_sum, vector<int>&ds, vector<int>&arr) {
        if(indx>=arr.size()) {
            ds.push_back(curr_sum);
            return;
        }
        
        solve(indx+1, curr_sum+arr[indx], ds, arr);
        solve(indx+1, curr_sum, ds, arr);
    }
    
    vector<int> subsetSums(vector<int> arr, int N) {
        vector<int>ds;
        solve(0, 0, ds, arr);
        return ds;
    }
};

// Approach 2
class Solution
{
public:
    vector<int> subsetSums(vector<int> arr, int N) {
        vector<int>ds;
        for(int i=0; i<(1<<N); ++i) {
            int num = i;
            int indx = 0;
            int sum = 0;
            while(num) {
                if(num&1) {
                    sum += arr[indx];
                }
                ++indx;
                num>>=1;
            }
            ds.push_back(sum);
        }
        
        return ds;
    }
};
