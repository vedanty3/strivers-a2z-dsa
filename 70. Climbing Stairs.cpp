class Solution {
	public:
		int climbStairs(int n) {

			int first = 1;
			int second = 0;
			int ans = 0;

			for(int i=0; i<n+1; ++i) {
				ans = first + second;

				first = second;
				second = ans;
			}

			return ans;
		}
};
