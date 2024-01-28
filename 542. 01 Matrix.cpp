class Solution {
	public:
		const vector<int>dx = {1, -1, 0, 0};
		const vector<int>dy = {0, 0, 1, -1};
		vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
			int m = mat.size();
			int n = mat[0].size();

			vector<vector<bool>>vis(m, vector<bool>(n, false));
			vector<vector<int>>dist(m, vector<int>(n, 0));

			queue<pair<pair<int, int>, int>>q;

			for(int i=0; i<m; ++i) {
				for(int j=0; j<n; ++j) {
					if(mat[i][j]==0) {
						q.push({{i, j}, 0});
						vis[i][j] = true;
					}
				}
			}

			while(!q.empty()) {
				int ro = q.front().first.first;
				int col = q.front().first.second;
				int dis = q.front().second;
				dist[ro][col] = dis;
				q.pop();

				for(int i=0; i<4; ++i) {
					int n_ro = dx[i] + ro;
					int n_col = dy[i] + col;

					if(n_ro<m and n_col<n and n_ro>=0 and n_col>=0 and !vis[n_ro][n_col] and mat[n_ro][n_col]==1) {
						q.push({{n_ro, n_col}, dis+1});
						vis[n_ro][n_col] = true;
					}
				}

			}

			return dist;
		}
};
