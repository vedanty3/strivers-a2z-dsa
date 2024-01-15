class Solution {
	public:
		int maxScore(vector<int>& cardPoints, int k) {
			int n = cardPoints.size();
			int ans = 0;

			for(int i=0; i<k; ++i) {
				ans = ans + cardPoints[i];
			}

			int curr = ans;
			int i = k;

			for(int j=n-1; j>n-1-k; --j) {
				curr += cardPoints[j];
				curr -= cardPoints[--i];
				ans = max(ans, curr);
			}

			return ans;
		}
};
