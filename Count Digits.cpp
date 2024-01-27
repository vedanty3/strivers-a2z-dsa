int countDigits(int n) {
	int ans = 0;
	int nn = n;

	while(n) {
		int last_digit = n%10;
		n /= 10;
		if(last_digit!=0 and nn%last_digit==0) {
			++ans;
		}
	}

	return ans;
}
