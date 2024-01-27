int upperBound(vector<int> &nums, int target, int n) {
	int lo = 0;
	int hi = n-1;
	int ans = 0;

	while(lo<=hi) {
		int mid = lo + (hi-lo)/2;
		if(nums[mid]>target) {
			hi = mid-1;
		} else {
			lo = mid+1;
			ans = lo;
		}
	}

	return ans;
}
