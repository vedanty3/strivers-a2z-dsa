class Solution {
	public:
		double solve(double x, int n) {
			if(n==1) {
				return x;
			} else if(n==0) {
				return 1;
			}

			double ans = solve(x, n/2);

			if(n&1) {
				ans = ans*ans*x;
			} else {
				ans = ans*ans;
			}

			return ans;
		}
		double myPow(double x, int n) {
			if(n<0) {
				return 1.0/solve(x, abs(n));
			}
			return solve(x, n);
		}
};

class Solution {
	public:
		double myPow(double x, int n) {
			double ans = 1.0;
			int fl = n < 0;
			long long int nn = n;

			if (fl) {
				nn = -1 * nn;
			}

			while (nn) {
				if (nn & 1) {
					ans *= x;
				}
				x *= x;
				nn >>= 1;
			}

			if (fl) {
				ans = 1 / ans;
			}

			return ans;
		}
};

