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
