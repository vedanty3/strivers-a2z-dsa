class Solution {
	public:
		int uniquePaths(int m, int n) {
			vector<int> next(n + 1, 0), curr(n + 1, 0);

			for (int i = m - 1; i >= 0; --i) {
				for (int j = n - 1; j >= 0; --j) {
					if (i == m - 1 and j == n - 1) {
						curr[j] = 1;
						continue;
					}
					curr[j] = next[j] + curr[j + 1];
				}
				next = curr;
			}
			return next[0];
		}
};

class Solution {
	public:
		int uniquePaths(int m, int n) {
			double res = 1;
			int r = m-1;
			int N = m+n-2;

			for (int i = 1; i<=r; ++i) {
				res = res * (N - r + i) / i;
			}

			return (int)res;
		}
};
