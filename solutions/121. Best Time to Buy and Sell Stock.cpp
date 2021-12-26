class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int prevMinPrice = INT_MAX, profit = 0;
        
        for(int price : prices) {
            profit = max(profit, price - prevMinPrice);
            prevMinPrice = min(prevMinPrice, price);
        }
        
        return profit;
    }
};
