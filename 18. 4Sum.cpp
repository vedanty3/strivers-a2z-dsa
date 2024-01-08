// TC: O(N^4)

class Solution {
	public:
		vector<vector<int>> fourSum(vector<int>& nums, int target) {
			int n = nums.size();
			set<vector<int>>st;
			sort(nums.begin(), nums.end());

			for(int i=0; i<n; ++i) {
				for(int j=i+1; j<n; ++j) {
					for(int k=j+1; k<n; ++k) {
						for(int l=k+1; l<n; ++l) {
							long long int sum = 1LL*nums[i] + 1LL*nums[j] + 1LL*nums[k] + 1LL*nums[l];
							if(sum==target) {
								st.insert({nums[i], nums[j], nums[k], nums[l]});
							}
						}
					}
				}
			}

			return {st.begin(), st.end()};
		}
};

// TC: O(N^3 * log(M)))

class Solution {
	public:
		vector<vector<int>> fourSum(vector<int>& nums, int target) {
			int n = nums.size();
			set<vector<int>>st1;

			for(int i=0; i<n; ++i) {
				for(int j=i+1; j<n; ++j) {
					set<long long>st;
					for(int k=j+1; k<n; ++k) {
						long long sum = nums[i] + nums[j];
						sum += nums[k];
						long long last = target - sum;
						if(st.find(last)!=st.end()) {
							vector<int>curr_ans = {nums[i], nums[j], nums[k], (int)(last)};
							sort(curr_ans.begin(), curr_ans.end());
							st1.insert(curr_ans);
						}
						st.insert(nums[k]);
					}
				}
			}

			vector<vector<int>>ans(st1.begin(), st1.end());
			return ans;
		}
};

// TC: O(N^3)

class Solution {
	public:
		vector<vector<int>> fourSum(vector<int>& nums, int target) {
			int n = nums.size();
			sort(nums.begin(), nums.end());
			vector<vector<int>>ans;

			for(int i=0; i<n; ++i) {
				if(i>0 and nums[i]==nums[i-1]) {
					continue;
				}
				for(int j=i+1; j<n; ++j) {
					if(j>i+1 and nums[j]==nums[j-1]) {
						continue;
					}
					int lo = j+1;
					int hi = n-1;
					while(lo<hi) {
						long long sum = nums[i];
						sum += nums[j];
						sum += nums[lo];
						sum += nums[hi];
						if(sum==target) {
							ans.push_back({nums[i], nums[j], nums[lo], nums[hi]});
							++lo;
							--hi;
							while(lo<hi and nums[lo]==nums[lo-1]) {
								++lo;
							}
							while(lo<hi and nums[hi]==nums[hi+1]) {
								--hi;
							}
						} else if(sum<target) {
							++lo;
						} else {
							--hi;
						}
					}

				}
			}

			return ans;
		}
};
