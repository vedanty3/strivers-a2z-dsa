class Solution {
	public:
		int findMin(vector<int>& arr) {
			int n = arr.size();
			int lo = 0;
			int hi = n-1;
			int ans = INT_MAX;

			while(lo<=hi) {
				int mid = lo + (hi-lo)/2;
				if(arr[lo]<=arr[hi]) {
					ans = min(ans, arr[lo]);
					break;
				} else if(arr[lo]<=arr[mid]) {
					ans = min(ans, arr[lo]);
					lo = mid + 1;
				} else if(arr[mid]<=arr[hi]) {
					ans = min(ans, arr[mid]);
					hi = mid-1;
				}
			}

			return ans;
		}
};
