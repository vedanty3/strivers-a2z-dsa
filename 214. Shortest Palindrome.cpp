class Solution {
private:
    vector<int> kmp(string& s) {
        int n = s.size();
        vector<int> lps(n, 0);
        for (int i = 1; i < n; ++i) {
            int j = lps[i - 1];
            while (j > 0 and s[i] != s[j]) {
                j = lps[j - 1];
            }
            if (s[i] == s[j]) {
                ++j;
            }
            lps[i] = j;
        }
        return lps;
    }

public:
    string shortestPalindrome(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        string k = s + "$" + t;
        int m = t.size();
        int n = k.size();
        vector<int> lps = kmp(k);
        string ans = t.substr(0, m - lps[n - 1]) + s;
        return ans;
    }
};