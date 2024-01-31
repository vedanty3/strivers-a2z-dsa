class Solution {
	public:
		const vector<int>dx = {1, -1, 0, 0};
		const vector<int>dy = {0, 0, 1, -1};

		int minimumEffortPath(vector<vector<int>>& heights) {
			int m = heights.size();
			int n = heights[0].size();
			vector<vector<int>>dist(m, vector<int>(n, 1e9));
			priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>pq;
			pq.push({0, {0, 0}});
			dist[0][0] = 0;

			while(!pq.empty()) {
				int ro = pq.top().second.first;
				int col = pq.top().second.second;
				int wt = pq.top().first;
				pq.pop();

				if(ro==m-1 and col==n-1) {
					return wt;
				}

				for(int i=0; i<4; ++i) {
					int n_ro = dx[i] + ro;
					int n_col = dy[i] + col;
					if(n_ro>=0 and n_col>=0 and n_ro<m and n_col<n) {
						int curr_effort = max(abs(heights[n_ro][n_col]-heights[ro][col]), wt);
						if(curr_effort<dist[n_ro][n_col]) {
							dist[n_ro][n_col] = curr_effort;
							pq.push({curr_effort, {n_ro, n_col}});
						}

					}
				}
			}

			return 0;
		}
};
