class Solution {
	public:
		vector<vector<int>> merge(vector<vector<int>>& a) {
			int n = a.size();
			sort(a.begin(), a.end());
			int s = a[0][0];
			int e = a[0][1];

			vector<vector<int>>ans;

			for(int i=1; i<n; ++i) {
				if(e<a[i][0]) {
					ans.push_back({s, e});
					s = a[i][0];
					e = a[i][1];
				}

				if(a[i][0]<=e and a[i][1]>=e) {
					e = a[i][1];
				}
			}

			ans.push_back({s, e});

			return ans;

		}
};
