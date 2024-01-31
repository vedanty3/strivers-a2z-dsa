class Solution {
	public:
		const vector<int>dx = {1, -1, 0, 0, -1, -1, 1, 1};
		const vector<int>dy = {0, 0, 1, -1, -1, 1, 1, -1};

		int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
			int n = grid.size();
			vector<vector<int>>dist(n, vector<int>(n, 1e9));
			priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>pq;
			pq.push({1, {0, 0}});
			dist[0][0] = 0;

			if(grid[0][0]==1) {
				return -1;
			}
			if(n-1==0) {
				return 1;
			}

			while(!pq.empty()) {
				int ro = pq.top().second.first;
				int col = pq.top().second.second;
				int wt = pq.top().first;
				pq.pop();

				if(ro==n-1 and col==n-1) {
					return wt;
				}

				for(int i=0; i<8; ++i) {
					int n_ro = ro + dx[i];
					int n_col = col + dy[i];

					if(n_ro>=0 and n_col>=0 and n_ro<n and n_col<n and (wt + 1)<dist[n_ro][n_col] and grid[n_ro][n_col]==0) {
						dist[n_ro][n_col] = wt + 1;
						pq.push({dist[n_ro][n_col], {n_ro, n_col}});
					}
				}
			}

			return -1;
		}
};
