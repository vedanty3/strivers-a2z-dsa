class Solution {
	public:
		int findContentChildren(vector<int>& g, vector<int>& s) {
			int ans = 0;
			int m = s.size();
			int n = g.size();

			sort(g.begin(), g.end());
			sort(s.begin(), s.end());

			int i = 0;
			int j = 0;

			while(i<m and j<n) {
				if(s[i]>=g[j]) {
					++ans;
					++i;
					++j;
				} else {
					++i;
				}
			}

			return ans;
		}
};
