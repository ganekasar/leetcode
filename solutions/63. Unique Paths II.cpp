class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int ROWS = obstacleGrid.size();
        int COLS = obstacleGrid[0].size();
        
        int dp[ROWS][COLS];
        
        memset(dp, 0, sizeof(dp));
        
        for(int i = 0; i < ROWS; i++) {
            for(int j = 0; j < COLS; j++) {
                if(obstacleGrid[i][j] == 1)
                    continue;
                
                if(i == 0 && j == 0)
                    dp[i][j] = 1;
                else if(i == 0)
                    dp[i][j] = dp[i][j-1];
                else if(j == 0)
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        
        return dp[ROWS-1][COLS-1];
    }
};
