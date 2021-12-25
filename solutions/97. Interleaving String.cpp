class Solution {
public:
    
    int dp[101][101];
    
    bool solve(string s1, string s2, string s3, int i, int j, int k) {
        if(i == s1.length() && j == s2.length() && k == s3.length())
            return true;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        bool result = false;
        
        if(i < s1.length() && s1[i] == s3[k])
            result = result || solve(s1, s2, s3, i+1, j, k+1);
        
        if(j < s2.length() && s2[j] == s3[k])
            result = result || solve(s1, s2, s3, i, j+1, k+1);
        
        return dp[i][j] = result;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length() + s2.length() != s3.length())
            return false;
        
        memset(dp, -1, sizeof(dp));
        
        return solve(s1, s2, s3, 0, 0, 0);
    }
};
