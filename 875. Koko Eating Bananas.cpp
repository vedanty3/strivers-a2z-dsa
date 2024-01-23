class Solution {
	public:
		bool isPossible(int k, int h, vector<int>& piles) {
			long long curr_time = 0;
			int n = piles.size();

			for (int i = 0; i < n; ++i) {
				curr_time += piles[i] / k + (piles[i] % k != 0);
			}

			return curr_time <= h;
		}

		int minEatingSpeed(vector<int>& piles, int h) {
			int n = piles.size();
			int lo = 1;
			int hi = *max_element(piles.begin(), piles.end());
			int ans = 0;

			while (lo <= hi) {
				int mid = lo + (hi - lo) / 2;
				if (isPossible(mid, h, piles)) {
					ans = mid;
					hi = mid - 1;
				} else {
					lo = mid + 1;
				}
			}

			return ans;
		}
};
