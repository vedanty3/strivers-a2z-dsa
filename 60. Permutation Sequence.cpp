class Solution {
	public:
		string getPermutation(int n, int k) {
			int f = 1;
			vector<int>val;

			for(int i=1; i<n; ++i) {
				f *= i;
				val.push_back(i);
			}

			val.push_back(n);

			string res;
			--k;

			while(1) {
				res = res + to_string(val[k/f]);
				val.erase(val.begin() + k/f);

				if(val.size()==0) {
					break;
				}

				k = k%f;
				f = f/val.size();
			}

			return res;
		}
};
