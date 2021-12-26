class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int N = triangle.size();
        
        vector<vector<int>> dp(N, vector<int>(N, 0));
        
        dp[0][0] = triangle[0][0];
        int answer = INT_MAX;
        
        for(int i = 1; i < N; i++) {
            for(int j = 0; j <= i; j++) {
                if(j == 0)
                    dp[i][j] = dp[i-1][j] + triangle[i][j];
                else if(j == i)
                    dp[i][j] = dp[i-1][j-1] + triangle[i][j];
                else
                    dp[i][j] = min(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j];
            }
        }
        
        for(int i = 0; i <= N-1; i++) {
            answer = min(answer, dp[N-1][i]);
        }
        
        return answer;
    }
};
