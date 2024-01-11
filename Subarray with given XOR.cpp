int Solution::solve(vector<int> &A, int B) {
	int n = A.size();
	int subarray_cnt = 0;
	int curr_xor = 0;
	unordered_map<int, int>mpp;

	for(int i=0; i<n; ++i) {
		curr_xor = curr_xor^A[i];
		if(curr_xor==B) {
			++subarray_cnt;
		}

		if(mpp.find(curr_xor^B)!=mpp.end()) {
			subarray_cnt += mpp[curr_xor^B];
		}

		mpp[curr_xor]++;
	}

	return subarray_cnt;
}

