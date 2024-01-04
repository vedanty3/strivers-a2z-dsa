class Solution {
	public:
		long long merge(long long s, long long e, int n, long long arr[]) {
			long long i=s;
			long long mid = s + (e-s)/2;
			long long j = mid+1;
			long long cnt = 0;
			vector<long long>temp;

			while(i<=mid and j<=e) {
				if(arr[i]>arr[j]) {
					cnt +=( mid - i + 1);
					temp.push_back(arr[j]);
					++j;
				} else {
					temp.push_back(arr[i]);
					++i;
				}
			}

			while(i<=mid) {
				temp.push_back(arr[i++]);
			}

			while(j<=e) {
				temp.push_back(arr[j++]);
			}

			int k = 0;

			for(int i=s; i<=e; ++i) {
				arr[i] = temp[k];
				++k;
			}

			return cnt;
		}

		long long mergeSort(long long s, long long e, int n, long long arr[]) {
			if(s>=e) {
				return 0;
			}

			long long mid = s + (e-s)/2;
			long long int cnt = mergeSort(s, mid, n, arr);
			cnt += mergeSort(mid+1, e, n, arr);
			cnt += merge(s, e, n, arr);

			return cnt;
		}

		long long int inversionCount(long long arr[], long long n) {
			return mergeSort(0, n-1, n, arr);
		}

};
