class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        
        if(n == 0 and m == 0) 
            return true;
        
        if(m == 0) 
            return false;
        
        vector<vector<bool>> dp(n+1, vector<bool>(m+1, false)); 
        
        dp[0][0] = true; 
        
        for(int j = 2; j <= m; j++) 
            dp[0][j] = dp[0][j-2] and (p[j-1] == '*');
        
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if((p[j-1] != '.') and (p[j-1] != '*')) 
                    dp[i][j] = (dp[i-1][j-1]) and (s[i-1] == p[j-1]);
                else if(p[j-1] == '.') 
                    dp[i][j] = dp[i-1][j-1];
                else if(j > 1) {
                    if((s[i-1] == p[j-2]) or (p[j-2] == '.')) 
                        dp[i][j] = dp[i-1][j] or dp[i][j-2];
                    else 
                        dp[i][j] = dp[i][j-2];
                }
            }
        }
        
        return dp[n][m];    
    }
};
