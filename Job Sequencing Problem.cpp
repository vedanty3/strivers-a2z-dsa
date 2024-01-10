class Solution {
	public:
		bool static comparator(Job&j1, Job&j2) {
			return j1.profit>j2.profit;
		}

		vector<int> JobScheduling(Job arr[], int n) {
			int max_deadline = arr[0].dead;
			for(int i=0; i<n; ++i) {
				max_deadline = max(max_deadline, arr[i].dead);
			}

			vector<int>jobs_sequence(max_deadline+1, -1);

			sort(arr, arr+n, comparator);

			int jobs_ct = 0;
			int max_profit = 0;

			for(int i=0; i<n; ++i) {
				for(int j=arr[i].dead; j>0; --j) {
					if(jobs_sequence[j]==-1) {
						jobs_sequence[j] = i;
						++jobs_ct;
						max_profit += arr[i].profit;
						break;
					}
				}
			}

			return {jobs_ct, max_profit};
		}
};

