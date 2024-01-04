class Solution {
	public:
		int maxSumIS(int arr[], int n) {
			vector<vector<int>>dp(n+1, vector<int>(n+1, 0));
			vector<int>next(n+1, 0);
			vector<int>curr(n+1, 0);

			for(int i=n-1; i>=0; --i) {
				for(int j=i-1; j>=-1; --j) {

					int max_sum = INT_MIN;

					if(j==-1) {
						max_sum = max(next[j+1], arr[i] + next[i+1]);
					} else {
						max_sum = next[j+1];
						if(arr[i]>arr[j]) {
							max_sum = max(max_sum, arr[i] + next[i+1]);
						}
					}
					curr[j+1] = max_sum;

				}
				next = curr;
			}


			return next[0];
		}
};

