// Approach 1

class Solution {
public:
    void sortColors(vector<int>& nums) {
        sort(nums.begin(), nums.end());
    }
};

// Approach 2

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int lo = 0;
        int hi = nums.size() - 1;
        int mid = 0;
        
        while(mid<=hi) {
            if(nums[mid]==0) {
                swap(nums[mid], nums[lo]);
                ++mid;
                ++lo;
            } else if(nums[mid]==1) {
                ++mid;
            } else {
                swap(nums[mid], nums[hi]);
                --hi;
            }
        }
    }
};
