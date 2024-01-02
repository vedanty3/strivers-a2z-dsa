class Solution {
public:
    void solve(int indx, vector<int>&candidates, vector<int>&ds, int target, vector<vector<int>>&ans) {
        if(indx>=candidates.size()) {
            if(target==0) {
                ans.push_back(ds);
            }
            return;
        }
        
        if(candidates[indx]<=target) {
            ds.push_back(candidates[indx]);
            solve(indx, candidates, ds, target - candidates[indx], ans);  
            ds.pop_back();
        }

        solve(indx+1, candidates, ds, target, ans);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>ds;
        vector<vector<int>>ans;
        solve(0, candidates, ds, target, ans);
        return ans;
    }
};
