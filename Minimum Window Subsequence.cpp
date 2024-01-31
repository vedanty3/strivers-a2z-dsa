string minWindow(string s, string t) {
	int i = 0;
	int j = 0;
	int m = s.size();
	int n = t.size();
	int start = -1;
	int min_window = INT_MAX;

	while(i<m) {
		if(s[i]==t[j]) {
			++j;
		}

		if(j==n) {
			--j;
			int end = i;

			while(j>=0) {
				if(s[i]==t[j]) {
					--j;
				}
				--i;
			}

			++i;
			++j;

			if(end-i+1<min_window) {
				min_window = end - i + 1;
				start = i;
			}
		}
		++i;
	}

	return min_window==INT_MAX ? "" : s.substr(start, min_window);
}

