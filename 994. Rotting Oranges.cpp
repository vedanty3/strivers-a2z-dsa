class Solution {
	public:
		const vector<int> dx = {1, -1, 0, 0};
		const vector<int> dy = {0, 0, 1, -1};

		int orangesRotting(vector<vector<int>>& grid) {
			int m = grid.size();
			int n = grid[0].size();
			int mini_time = 0;
			int fresh_ct = 0;
			int rotten_ct = 0;
			queue<pair<pair<int, int>, int>> q;

			for (int i = 0; i < m; ++i) {
				for (int j = 0; j < n; ++j) {
					if (grid[i][j] == 2) {
						q.push({{i, j}, 0});
						grid[i][j] = 0;
					} else if (grid[i][j] == 1) {
						++fresh_ct;
					}
				}
			}

			while (!q.empty()) {
				int ro = q.front().first.first;
				int col = q.front().first.second;
				int curr_time = q.front().second;
				mini_time = max(mini_time, curr_time);
				q.pop();

				for (int i = 0; i < 4; ++i) {
					int n_ro = ro + dx[i];
					int n_col = col + dy[i];
					if (n_ro >= 0 and n_col >= 0 and n_ro < m and n_col < n and
					    grid[n_ro][n_col] == 1) {
						grid[n_ro][n_col] = 2;
						q.push({{n_ro, n_col}, curr_time + 1});
						++rotten_ct;
					}
				}
			}

			if (fresh_ct != rotten_ct) {
				return -1;
			}

			return mini_time;
		}
};
