// Approach 1

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = INT_MIN;
        
        for(int i=0; i<nums.size(); ++i) {
            for(int j=i; j<nums.size(); ++j) {
                int curr_sum = 0;
                for(int k=i; k<=j; ++k) {
                    curr_sum += nums[k];
                }
                max_sum = max(max_sum, curr_sum);
            }
        }
        
        return max_sum;
    }
};

// Approach 2

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = INT_MIN;
        
        for(int i=0; i<nums.size(); ++i) {
            int curr_sum = 0;
            for(int j=i; j<nums.size(); ++j) {
                curr_sum += nums[j];
                max_sum = max(max_sum, curr_sum);
            }
        }
        
        return max_sum;
    }
};

// Approach 3

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = INT_MIN;
        int curr_sum = 0;
        
        for(int i=0; i<nums.size(); ++i) {
            curr_sum += nums[i];
            if(max_sum<curr_sum) {
                max_sum = curr_sum;
            }
            if(curr_sum<0) {
                curr_sum = 0;
            }
        }
        
        return max_sum;
    }
};
