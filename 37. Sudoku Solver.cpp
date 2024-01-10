class Solution {
	public:
		bool isSafe(int ro, int col, char ch, vector<vector<char>>& board) {
			for (int i = 0; i < 9; ++i) {
				if (board[i][col] == ch or board[ro][i] == ch) {
					return false;
				}
			}

			int sx = ro / 3 * 3;
			int sy = col / 3 * 3;

			for (int i = sx; i < sx + 3; ++i) {
				for (int j = sy; j < sy + 3; ++j) {
					if (board[i][j] == ch) {
						return false;
					}
				}
			}

			return true;
		}

		bool solve(int indx1, int indx2, vector<vector<char>>& board) {
			if (indx1 >= 9) {
				return true;
			}

			if (indx2 >= 9) {
				return solve(indx1 + 1, 0, board);
			}

			if (board[indx1][indx2] != '.') {
				return solve(indx1, indx2 + 1, board);
			}

			for (int ch = '1'; ch <= '9'; ++ch) {
				if (isSafe(indx1, indx2, ch, board)) {
					board[indx1][indx2] = ch;
					if (solve(indx1, indx2 + 1, board)) {
						return true;
					}
				}
			}

			board[indx1][indx2] = '.';
			return false;
		}

		void solveSudoku(vector<vector<char>>& board) {
			solve(0, 0, board);
		}
};
