class Solution {
	public:
		const vector<int> dx = {1, -1, 0, 0};
		const vector<int> dy = {0, 0, 1, -1};

		void dfs(int ro, int col, vector<vector<bool>>& vis,
		         vector<vector<char>>& board) {
			int m = board.size();
			int n = board[0].size();
			vis[ro][col] = true;

			for (int i = 0; i < 4; ++i) {
				int n_ro = dx[i] + ro;
				int n_col = dy[i] + col;
				if (n_ro >= 0 and n_col >= 0 and n_ro < m and n_col < n and
				    board[n_ro][n_col] == 'O' and !vis[n_ro][n_col]) {
					dfs(n_ro, n_col, vis, board);
				}
			}
		}

		void solve(vector<vector<char>>& board) {
			int m = board.size();
			int n = board[0].size();
			vector<vector<bool>> vis(m + 1, vector<bool>(n + 1, false));

			for (int i = 0; i < m; ++i) {
				if (!vis[i][0] and board[i][0] == 'O') {
					vis[i][0] = true;
					dfs(i, 0, vis, board);
				}
			}

			for (int i = 0; i < m; ++i) {
				if (!vis[i][n - 1] and board[i][n - 1] == 'O') {
					vis[i][n - 1] = true;
					dfs(i, n - 1, vis, board);
				}
			}

			for (int j = 0; j < n; ++j) {
				if (!vis[0][j] and board[0][j] == 'O') {
					vis[0][j] = true;
					dfs(0, j, vis, board);
				}
			}

			for (int j = 0; j < n; ++j) {
				if (!vis[m - 1][j] and board[m - 1][j] == 'O') {
					vis[m - 1][j] = true;
					dfs(m - 1, j, vis, board);
				}
			}

			for (int i = 0; i < m; ++i) {
				for (int j = 0; j < n; ++j) {
					if (board[i][j] == 'O' and !vis[i][j]) {
						board[i][j] = 'X';
					}
				}
			}
		}
};
