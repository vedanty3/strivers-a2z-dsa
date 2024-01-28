class Solution {
	public:
		const vector<int>dx = {1, -1, 0, 0};
		const vector<int>dy = {0, 0, 1, -1};

		void dfs(int ro, int col, int ini_color, int color, vector<vector<int>>&image) {
			int m = image.size();
			int n = image[0].size();
			image[ro][col] = color;

			for(int i=0; i<4; ++i) {
				int n_ro = ro + dx[i];
				int n_col = dy[i] + col;

				if(n_ro<m and n_col<n and n_ro>=0 and n_col>=0 and image[n_ro][n_col]==ini_color) {
					dfs(n_ro, n_col, ini_color, color, image);
				}
			}
		}

		vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
			int m = image.size();
			int n = image[0].size();
			int ini_color = image[sr][sc];

			if(ini_color==color) {
				return image;
			}

			dfs(sr, sc, ini_color, color, image);

			return image;
		}
};
