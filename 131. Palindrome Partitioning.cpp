class Solution {
public:
    bool isPalindrome(int i, int j, string&s) {
        while(i<=j) {
            if(s[i]!=s[j]) {
                return false;
            }
            ++i;
            --j;
        }
        return true;
    }
    
    void solve(int indx, string&s, vector<string>&ds, vector<vector<string>>&ans) {
        if(indx>=s.size()) {
            ans.push_back(ds);
            return;
        }
        for(int i=indx; i<s.size(); ++i) {
            if(isPalindrome(indx, i, s)) {
                ds.push_back(s.substr(indx, i-indx+1));
                solve(i+1, s, ds, ans);
                ds.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<string>ds;
        vector<vector<string>>ans;
        solve(0, s, ds, ans);
        return ans;
    }
};
