vector<int>dx = {1, -1, 0, 0};
vector<int>dy = {0, 0, 1, -1};
void bfs(int i, int j, vector<vector<bool>>&vis, vector<vector<int>>&grid) {
	queue<pair<int, int>>q;
	q.push({i, j});
	vis[i][j] = true;
	int m = grid.size();
	int n = grid[0].size();

	while(!q.empty()) {
		int ro = q.front().first;
		int col = q.front().second;
		q.pop();

		for(int i=0; i<4; ++i) {
			int n_ro = dx[i] + ro;
			int n_col = dy[i] + col;

			if(n_ro>=0 and n_col>=0 and n_ro<m and n_col<n and !vis[n_ro][n_col] and grid[n_ro][n_col]==0) {
				vis[n_ro][n_col] = true;
				q.push({n_ro, n_col});
			}
		}
	}
	return;
}

int matrixTraps(int N,int M,vector<vector<int>> &grid) {
	int m = grid.size();
	int n = grid[0].size();
	vector<vector<bool>>vis(m, vector<bool>(n, false));

	// first and last row
	for(int j=0; j<n; ++j) {
		if(!vis[0][j] and grid[0][j]==0) {
			bfs(0, j, vis, grid);
		}
		if(!vis[m-1][j] and grid[m-1][j]==0) {
			bfs(m-1, j, vis, grid);
		}
	}

	// first and last col
	for(int i=0; i<m; ++i) {
		if(!vis[i][0] and grid[i][0]==0) {
			bfs(i, 0, vis, grid);
		}
		if(!vis[i][n-1] and grid[i][n-1]==0) {
			bfs(i, n-1, vis, grid);
		}
	}

	int ans = 0;
	for(int i=0; i<m; ++i) {
		for(int j=0; j<n; ++j) {
			if(!vis[i][j] and grid[i][j]==0) {
				++ans;
			}
		}
	}

	return ans;
}
