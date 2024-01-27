int gcd(int a, int b) {
	if(b==0) {
		return a;
	}

	return gcd(b, a%b);
}

int calcGCD(int n, int m) {
	return gcd(m, n);
}
