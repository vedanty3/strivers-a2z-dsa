int largestPowerOfTwo(int N) {
	int p = 0;
	while((1<<p)<=N) {
		++p;
	}
	return p-1;
}

int countSetBits(int N) {
	if(N<=0) {
		return 0;
	}

	int largest_power_of_2 = largestPowerOfTwo(N);

	int ans = (1<<(largest_power_of_2-1)) * largest_power_of_2;
	ans = ans + (N - (1<<largest_power_of_2) + 1);
	ans = ans + countSetBits(N - (1<<largest_power_of_2));

	return ans;
}
