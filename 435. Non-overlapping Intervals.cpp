class Solution {
	public:
		int eraseOverlapIntervals(vector<vector<int>>& a) {
			int n = a.size();
			int ans = 0;
			sort(a.begin(), a.end());
			int s = a[0][0];
			int e = a[0][1];

			for(int i=1; i<n; ++i) {
				if(e>a[i][0]) {
					++ans;
					e = min(e, a[i][1]);
					continue;
				}
				s = a[i][0];
				e = a[i][1];
			}

			return ans;
		}
};
