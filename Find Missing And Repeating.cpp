class Solution {
	public:
		vector<int> findTwoElement(vector<int> arr, int n) {
			int all_bits = 0;

			for(int i=1; i<=n; ++i) {
				all_bits = all_bits^i;
				all_bits = all_bits^arr[i-1];
			}

			int ith_bit = 0;

			while(all_bits) {
				if(all_bits&1) {
					break;
				}
				all_bits>>=1;
				++ith_bit;
			}

			int mask = 1<<ith_bit;

			int set_bit = 0;
			int unset_bit = 0;

			for(int i=0; i<n; ++i) {
				if(mask&arr[i]) {
					set_bit ^= arr[i];
				} else {
					unset_bit ^= arr[i];
				}

				if((i+1)&mask) {
					set_bit ^= (i+1);
				} else {
					unset_bit ^= (i+1);
				}
			}

			vector<int>res;
			for(int i=0; i<n; ++i) {
				if(arr[i]==set_bit) {
					res.push_back(set_bit);
					res.push_back(unset_bit);
				}
				if(arr[i]==unset_bit) {
					res.push_back(unset_bit);
					res.push_back(set_bit);
				}
			}

			return res;
		}
};
