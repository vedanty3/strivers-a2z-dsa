vector<int> twoOddNum(vector<int> arr) {
	int total_xor = 0;

	for(auto i : arr) {
		total_xor ^= i;
	}

	int mask = total_xor & (~(total_xor-1));
	int first = 0;
	int second = 0;

	for(auto i : arr) {
		if(i&mask) {
			first ^= i;
		} else {
			second ^= i;
		}
	}

	vector<int>ans;
	if(first<second) {
		ans = {second, first};
	} else {
		ans = {first, second};
	}

	return ans;
}
