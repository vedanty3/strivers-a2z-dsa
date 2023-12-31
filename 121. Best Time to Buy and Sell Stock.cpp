// Approach 1

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        
        for(int i=0; i<prices.size(); ++i) {
            for(int j=i+1; j<prices.size(); ++j) {
                max_profit = max(max_profit, prices[j] - prices[i]);
            }
        }
        
        return max_profit;
    }
};

// Approach 2

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int buy_price = prices[0];
        
        for(int i=0; i<prices.size(); ++i) {
            max_profit = max(max_profit, prices[i] - buy_price);
            if(buy_price>prices[i]) {
                buy_price = prices[i];
            }
        }
        
        return max_profit;
    }
};
