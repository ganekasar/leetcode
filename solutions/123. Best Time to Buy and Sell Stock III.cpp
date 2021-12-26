class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int hold1 = INT_MIN, hold2 = INT_MIN;
        int release1 = 0, release2 = 0;
        
        for(auto x : prices) {
            release2 = max(release2, hold2 + x); // profit earned after selling second stock
            hold2 = max(hold2, release1 - x); // amount spend to buy second stock
            
            release1 = max(release1, hold1 + x); // profit earned by selling first stock
            hold1 = max(hold1, -x); // amount spend to buy first stock
        }
        
        return release2;
    } 
};
​
// hold1 --> release1 --> hold2 --> release2
