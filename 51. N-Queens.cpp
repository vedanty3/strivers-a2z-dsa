class Solution {
	public:
		bool isPossible(int ro, int col, vector<string>& ds) {

			int i = ro, j = col;

			while (ro >= 0) {
				if (ds[ro][col] == 'Q') {
					return false;
				}
				--ro;
			}

			ro = i;

			while (ro >= 0 and col >= 0) {
				if (ds[ro][col] == 'Q') {
					return false;
				}
				--ro;
				--col;
			}

			ro = i;
			col = j;

			while (ro >= 0 and col < ds.size()) {
				if (ds[ro][col] == 'Q') {
					return false;
				}
				--ro;
				++col;
			}

			return true;
		}

		void solve(int ro, vector<string>& ds, vector<vector<string>>& ans, int n) {
			if (ro >= n) {
				ans.push_back(ds);
				return;
			}
			for (int i = 0; i < n; ++i) {
				if (isPossible(ro, i, ds)) {
					ds[ro][i] = 'Q';
					solve(ro + 1, ds, ans, n);
					ds[ro][i] = '.';
				}
			}
		}

		vector<vector<string>> solveNQueens(int n) {
			string s(n, '.');
			vector<string> ds(n, s);
			vector<vector<string>> ans;
			solve(0, ds, ans, n);
			return ans;
		}
};
