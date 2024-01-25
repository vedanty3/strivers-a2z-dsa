class Solution {
	private:
		static bool comparator(Item &i1, Item &i2) {
			double unit1_cost = (i1.value*1.0)/(i1.weight*1.0);
			double unit2_cost = (i2.value*1.0)/(i2.weight*1.0);
			return unit1_cost>unit2_cost;
		}

	public:
		double fractionalKnapsack(int W, Item arr[], int n) {
			double res = 0;
			sort(arr, arr+n, comparator);

			for(int i=0; i<n; ++i) {
				if(arr[i].weight>W) {
					double curr_res = (arr[i].value*1.0)/(arr[i].weight*1.0);
					curr_res *= W;
					res += curr_res;
					break;
				} else {
					res += arr[i].value;
					W -= arr[i].weight;
				}
			}

			return res;
		}

};
