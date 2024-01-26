vector<int>seive_of_erastosthenes(int n) {
	vector<bool>p(n+1, true);
	vector<int>ans;

	p[0] = p[1] = false;

	for(int i=2; i<=n; ++i) {
		if(p[i]) {
			if(n%i==0) {
				ans.push_back(i);
			}
			for(int j=i*i; j<=n; j+=i) {
				p[j] = 0;
			}
		}
	}

	return ans;
}

vector<int> countPrimes(int n) {
	vector<int>sieve = seive_of_erastosthenes(n);
	return sieve;
}
