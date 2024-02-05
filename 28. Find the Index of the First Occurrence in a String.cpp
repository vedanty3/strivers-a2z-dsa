class Solution {
private:
    vector<int> z_function(string& s) {
        int n = s.size();
        int l = 0;
        int r = 0;
        vector<int> z(n, 0);
        for (int i = 1; i < n; ++i) {
            if (i > r) {
                l = r = i;
                while (r < n and s[r] == s[r - l]) {
                    ++r;
                }
                z[i] = r - l;
                --r;
            } else {
                int end = i - l;
                if (z[end] < r - i + 1) {
                    z[i] = z[end];
                } else {
                    l = i;
                    while (r < n and s[r] == s[r - l]) {
                        ++r;
                    }
                    z[i] = r - l;
                    --r;
                }
            }
        }
        return z;
    }

public:
    int strStr(string haystack, string needle) {
        string s = needle + "#" + haystack;
        int n = s.size();
        int m = needle.size();
        int ans = -1;
        vector<int> z = z_function(s);

        for (int i = m; i < n; ++i) {
            if (z[i] == m) {
                ans = i - m - 1;
                break;
            }
        }

        return ans;
    }
};