int countDigits(int n) {
	int cnt = 0;
	while(n) {
		++cnt;
		n /= 10;
	}
	return cnt;
}

bool checkArmstrong(int n) {
	int k = countDigits(n);
	int nn = n;
	int sum = 0;

	while(n) {
		sum += pow(n%10, k);
		n /= 10;
	}

	return sum==nn;
}

