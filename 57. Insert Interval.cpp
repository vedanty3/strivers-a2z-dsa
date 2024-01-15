class Solution {
	public:
		vector<vector<int>> insert(vector<vector<int>>& a,
		vector<int>& newInterval) {
			int n = a.size();
			int s = newInterval[0];
			int e = newInterval[1];
			vector<vector<int>> ans;

			for (int i = 0; i < n; ++i) {
				if (s > a[i][1]) {
					ans.push_back({a[i][0], a[i][1]});
					continue;
				}
				if (a[i][0] > e) {
					ans.push_back({s, e});
					s = a[i][0];
					e = a[i][1];
					continue;
				}
				if (s <= a[i][0] and e <= a[i][1]) {
					e = a[i][1];
				} else if (s >= a[i][0] and e >= a[i][1]) {
					s = a[i][0];
				} else if (s >= a[i][0] and e <= a[i][1]) {
					s = a[i][0];
					e = a[i][1];
				}
			}
			ans.push_back({s, e});
			return ans;
		}
};
