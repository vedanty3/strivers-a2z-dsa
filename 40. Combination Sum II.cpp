class Solution {
public:
    void solve(int indx, int target, vector<int>& candidates, vector<int>& ds,
               vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(ds);
            return;
        }
        for (int i = indx; i < candidates.size(); ++i) {
            if (indx != i and candidates[i] == candidates[i - 1]) {
                continue;
            }
            if (candidates[i] <= target) {
                ds.push_back(candidates[i]);
                solve(i + 1, target - candidates[i], candidates, ds, ans);
                ds.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> ds;
        vector<vector<int>> ans;
        solve(0, target, candidates, ds, ans);
        return ans;
    }
};
