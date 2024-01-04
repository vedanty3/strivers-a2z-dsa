class Solution {
	public:
		const vector<int> dx = {1, -1, 0, 0};
		const vector<int> dy = {0, 0, 1, -1};

		void bfs(int i, int j, int m, int n, vector<vector<bool>>& vis,
		         vector<vector<char>>& grid) {
			queue<pair<int, int>> q;
			q.push({i, j});
			vis[i][j] = true;

			while (!q.empty()) {
				int ro = q.front().first;
				int col = q.front().second;
				q.pop();

				for (int k = 0; k < 4; ++k) {
					int n_ro = ro + dx[k];
					int n_col = col + dy[k];

					if (n_ro >= 0 and n_col >= 0 and n_ro < m and n_col < n and
					    !vis[n_ro][n_col] and grid[n_ro][n_col] == '1') {
						vis[n_ro][n_col] = true;
						q.push({n_ro, n_col});
					}
				}
			}
		}

		int numIslands(vector<vector<char>>& grid) {
			int m = grid.size();
			int n = grid[0].size();
			int islands = 0;
			vector<vector<bool>> vis(m, vector<bool>(n, false));

			for(int i=0; i<m; ++i) {
				for(int j=0; j<n; ++j) {
					if(!vis[i][j] and grid[i][j]=='1') {
						bfs(i, j, m, n, vis, grid);
						++islands;
					}
				}
			}

			return islands;
		}
};
