class Solution {
	public:
		int findPlatform(int arr[], int dep[], int n) {
			int i = 1;
			int j = 0;
			int maxi_platforms = 1;
			int needed_platforms = 1;

			sort(arr, arr+n);
			sort(dep, dep+n);

			while(i<n and j<n) {
				if(arr[i]<=dep[j]) {
					++maxi_platforms;
					++i;
				} else {
					++j;
					--maxi_platforms;
				}
				needed_platforms = max(needed_platforms, maxi_platforms);
			}

			return needed_platforms;
		}
};
