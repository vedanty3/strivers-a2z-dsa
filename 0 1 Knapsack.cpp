int maxProfit(vector<int> &values, vector<int> &weights, int n, int w) {
	vector<int>next(w+1, 0);
	vector<int>curr(w+1, 0);

	for(int i=n-1; i>=0; --i) {
		for(int j=w; j>=0; --j) {
			int max_profit = 0;
			if(weights[i]<=j) {
				max_profit = max(values[i] + next[j-weights[i]], next[j]);
			} else {
				max_profit = next[j];
			}
			curr[j] = max_profit;
		}
		next = curr;
	}

	return next[w];
}

// Single Array Space Optimization

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w) {
	vector<int>curr(w+1, 0);

	for(int i=n-1; i>=0; --i) {
		for(int j=w; j>=0; --j) {
			int max_profit = 0;
			if(weights[i]<=j) {
				max_profit = max(values[i] + curr[j-weights[i]], curr[j]);
			} else {
				max_profit = curr[j];
			}
			curr[j] = max_profit;
		}
	}

	return curr[w];
}
