int solve(int n) {
	int nn = n;
	int sum = 0;

	for(int i=1; i*i<=nn; ++i) {
		if(nn%i==0) {
			if(nn/i==i) {
				sum += i;
			} else {
				sum += (nn/i + i);
			}
		}
	}

	return sum;
}

int sumOfAllDivisors(int n) {
	int sum = 0;
	for(int i=1; i<=n; ++i) {
		sum += solve(i);
	}
	return sum;
}
