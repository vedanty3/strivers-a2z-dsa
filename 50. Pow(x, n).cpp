class Solution {
	public:
		double myPow(double x, int n) {
			int fl = n<0 ? 1 : 0;
			double res = 1.0;
			n = abs(n);

			while(n) {
				if(n&1) {
					res *= x;
				}
				x *= x;
				n >>= 1;
			}

			return fl ? 1.0/res : res;
		}
};
