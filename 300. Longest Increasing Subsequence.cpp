// Recursion

class Solution {
	public:
		int solve(int indx, int prev_indx, vector<int>&nums) {
			if(indx>=nums.size()) {
				return 0;
			}
			int max_length = INT_MIN;
			if(prev_indx==-1) {
				max_length = max(1 + solve(indx+1, indx, nums), solve(indx+1, prev_indx, nums));
			} else {
				if(nums[indx]>nums[prev_indx]) {
					max_length = max(1 + solve(indx+1, indx, nums), solve(indx+1, prev_indx, nums));
				} else {
					max_length = solve(indx+1, prev_indx, nums);
				}
			}

			return max_length;
		}

		int lengthOfLIS(vector<int>& nums) {
			return solve(0, -1, nums);
		}
};

// Memoization

class Solution {
	public:
		int solve(int indx, int prev_indx, vector<int>&nums, vector<vector<int>>&dp) {
			if(indx>=nums.size()) {
				return 0;
			}
			if(dp[indx][prev_indx+1]!=-1) {
				return dp[indx][prev_indx+1];
			}
			int max_length = INT_MIN;
			if(prev_indx==-1) {
				max_length = max(1 + solve(indx+1, indx, nums, dp), solve(indx+1, prev_indx, nums, dp));
			} else {
				if(nums[indx]>nums[prev_indx]) {
					max_length = max(1 + solve(indx+1, indx, nums, dp), solve(indx+1, prev_indx, nums, dp));
				} else {
					max_length = solve(indx+1, prev_indx, nums, dp);
				}
			}

			return dp[indx][prev_indx+1] = max_length;
		}

		int lengthOfLIS(vector<int>& nums) {
			vector<vector<int>>dp(nums.size(), vector<int>(nums.size()+1, -1));
			return solve(0, -1, nums, dp);
		}
};

// Tabulation

class Solution {
	public:
		int lengthOfLIS(vector<int>& nums) {
			int n = nums.size();
			vector<vector<int>>dp(n+1, vector<int>(n+1, 0));

			for(int i=n-1; i>=0; --i) {
				for(int j=i-1; j>=-1; --j) {
					if(j==-1) {
						dp[i][j+1] = max(1 + dp[i+1][i+1], dp[i+1][j+1]);
					} else {
						if(nums[i]>nums[j]) {
							dp[i][j+1] = max(1 + dp[i+1][i+1], dp[i+1][j+1]);
						} else {
							dp[i][j+1] = dp[i+1][j+1];
						}
					}
				}
			}

			return dp[0][0];
		}
};

// Space Optimized

class Solution {
	public:
		int lengthOfLIS(vector<int>& nums) {
			int n = nums.size();
			vector<int>next(n+1, 0), curr(n+1, 0);

			for(int i=n-1; i>=0; --i) {
				for(int j=i-1; j>=-1; --j) {
					if(j==-1) {
						curr[j+1] = max(1 + next[i+1], next[j+1]);
					} else {
						if(nums[i]>nums[j]) {
							curr[j+1] = max(1 + next[i+1], next[j+1]);
						} else {
							curr[j+1] = next[j+1];
						}
					}
				}
				next = curr;
			}

			return next[0];
		}
};

// Space Complexity: O(N)

class Solution {
	public:
		int lengthOfLIS(vector<int>& nums) {
			int maxi = 1;
			vector<int>dp(nums.size(), 1);

			for(int i=0; i<nums.size(); ++i) {
				for(int j=0; j<i; ++j) {
					if(nums[i]>nums[j]) {
						dp[i] = max(dp[i], 1+dp[j]);
					}
				}
				maxi = max(maxi, dp[i]);
			}

			return maxi;
		}
};

// Print LIS

class Solution {
	public:
		int lengthOfLIS(vector<int>& nums) {
			int n = nums.size();
			vector<int> dp(n, 1);
			vector<int> hash(n, 0);

			for (int i = 0; i < n; ++i) {
				hash[i] = i;
			}

			vector<int> lis;
			int maxi = 1;
			int max_indx = 0;

			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < i; ++j) {
					if (nums[i] > nums[j] and dp[j] + 1 > dp[i]) {
						dp[i] = 1 + dp[j];
						hash[i] = j;
					}
				}

				if (maxi < dp[i]) {
					maxi = dp[i];
					max_indx = i;
				}
			}

			stack<int> ans;
			ans.push(nums[max_indx]);

			while(max_indx != hash[max_indx]) {
				max_indx = hash[max_indx];
				ans.push(nums[max_indx]);
			}

			while(!ans.empty()) {
				cout<<ans.top()<<" ";
				ans.pop();
			}

			cout<<endl;

			return maxi;
		}
};

