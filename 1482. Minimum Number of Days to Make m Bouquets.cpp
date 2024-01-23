class Solution {
	public:
		bool canMakeMBouquets(int mid, int m, int k, vector<int>& bloomDay) {
			int bouquet_cnt = 0;
			int n = bloomDay.size();
			int curr_flower_cnt = 0;

			for (int i = 0; i < n; ++i) {
				if (bloomDay[i] <= mid) {
					curr_flower_cnt++;
				} else {
					curr_flower_cnt = 0;
				}
				if (curr_flower_cnt >= k) {
					++bouquet_cnt;
					curr_flower_cnt = 0;
				}
			}
			return bouquet_cnt >= m;
		}
		int minDays(vector<int>& bloomDay, int m, int k) {
			int n = bloomDay.size();
			int ans = -1;
			int lo = 1;
			int hi = 1e9;

			while (lo <= hi) {
				int mid = lo + (hi - lo) / 2;
				if (canMakeMBouquets(mid, m, k, bloomDay)) {
					ans = mid;
					hi = mid - 1;
				} else {
					lo = mid + 1;
				}
			}

			return ans;
		}
};
