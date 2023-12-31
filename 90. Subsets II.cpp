

// Approach 1

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>>st;
        
        for(int i=0; i<(1<<nums.size()); ++i) {
            int num = i;
            int indx = 0;
            vector<int>ds;
            while(num) {
                if(num&1) {
                    ds.push_back(nums[indx]);
                }
                ++indx;
                num>>=1;
            }
            sort(ds.begin(), ds.end());
            st.insert(ds);
        }
        
        return {st.begin(), st.end()};
    }
};

// Approach 2

class Solution {
public:
    void solve(int indx, vector<int>&ds, vector<int>&nums, set<vector<int>>&st) {
        if(indx>=nums.size()) {
            st.insert(ds);
            return;
        }
        ds.push_back(nums[indx]);
        solve(indx+1, ds, nums, st);
        ds.pop_back();
        solve(indx+1, ds, nums, st);
        
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>>st;
        vector<int>ds;
        sort(nums.begin(), nums.end());
        solve(0, ds, nums, st);
        return {st.begin(), st.end()};
    }
};

// Approach 3

class Solution {
public:
    void solve(int indx, vector<int>&ds, vector<int>&nums, vector<vector<int>>&res) {
        res.push_back(ds);
        for(int i=indx; i<nums.size(); ++i) {
            if(i!=indx and nums[i]==nums[i-1]) {
                continue;
            }
            ds.push_back(nums[i]);
            solve(i+1, ds, nums, res);
            ds.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>ds;
        sort(nums.begin(), nums.end());
        solve(0, ds, nums, res);
        return res;
    }
};

