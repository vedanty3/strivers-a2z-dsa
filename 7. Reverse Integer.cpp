class Solution {
	public:
		int reverse(int x) {
			int fl = x<0 ? -1 : 1;
			x = abs(x);

			long long int res = 0;

			while(x) {
				int last_digit = x%10;
				x /= 10;

				res += last_digit;
				res = res*10;
			}

			res /= 10;

			if(res<=pow(-2, 31) or res>=pow(2, 31)) {
				return 0;
			}

			return res*fl;
		}
};
