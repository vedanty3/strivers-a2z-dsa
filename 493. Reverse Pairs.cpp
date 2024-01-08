class Solution {
	public:
		int merge(int s, int e, vector<int>&nums) {
			int mid = s + (e-s)/2;
			int i = s;
			int j = mid+1;
			int reverse_pairs_cnt = 0;
			vector<int>temp;

			for(int i=s; i<=mid; ++i) {
				while(j<=e and nums[i]>(2LL*nums[j])) {
					++j;
				}
				reverse_pairs_cnt += j - mid - 1;
			}

			i=s;
			j = mid+1;

			while(i<=mid and j<=e) {
				if(nums[i]>nums[j]) {
					temp.push_back(nums[j++]);
				} else {
					temp.push_back(nums[i++]);
				}
			}

			while(i<=mid) {
				temp.push_back(nums[i++]);
			}

			while(j<=e) {
				temp.push_back(nums[j++]);
			}

			int k=0;

			for(int i=s; i<=e; ++i) {
				nums[i] = temp[k++];
			}

			return reverse_pairs_cnt;
		}

		int mergeSort(int s, int e, vector<int>&nums) {
			if(s>=e) {
				return 0;
			}

			int mid = s + (e-s)/2;
			int reverse_pairs_cnt = mergeSort(s, mid, nums);
			reverse_pairs_cnt += mergeSort(mid+1, e, nums);
			reverse_pairs_cnt += merge(s, e, nums);
			return reverse_pairs_cnt;
		}

		int reversePairs(vector<int>& nums) {
			return mergeSort(0, nums.size()-1, nums);
		}
};
