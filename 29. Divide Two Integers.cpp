class Solution {
	public:
		int divide(int dividend, int divisor) {
			if(dividend==INT_MIN and divisor==-1) {
				return INT_MAX;
			}

			if(dividend==INT_MIN and divisor==1) {
				return INT_MIN;
			}

			long long dd = abs(dividend);
			long long dv = abs(divisor);

			int ans = 0;

			while(dv<=dd) {
				long long sum = dv;
				long long count = 1;

				while((sum<<1)<= dd) {
					sum = sum<<1;
					count = count<<1;
				}

				ans += count;
				dd -= sum;
			}

			if(dividend<0 and divisor>0) {
				return -ans;
			}

			if(dividend>0 and divisor<0) {
				return  -ans;
			}

			return ans;
		}
};
