class Solution {
public:
    int candy(vector<int>& ratings) {
        int candies = 1;
        int up = 0, down = 0, peak = 0;
        
        for(int i = 1; i < ratings.size(); i++) {
            if(ratings[i-1] < ratings[i]) {
                up++;
                peak = up;
                down = 0;
                candies += (up + 1);
            } else if(ratings[i-1] > ratings[i]) {
                up = 0;
                down++;
                candies += down;
                
                if(peak < down)
                    candies++;  // evevate the peak
            } else {
                peak = up = down = 0;
                candies++;
            }
        }
        
        return candies;
    }
};
