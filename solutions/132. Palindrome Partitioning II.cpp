class Solution {
public:
​
    int minCut(string str) {
        int n = str.size();    
        
        if(n <= 1)
            return 0;
        
        bool pal[n][n];
        int dp[n];
        
        for(int i=0; i<n; i++) {
            pal[i][i] = true;
        }
        
        for(int L=2; L<=n; L++) {
            for(int i=0; i<=n-L; i++) {
                int j = i+L-1;
                
                if(L == 2) {
                    pal[i][j] = (str[i] == str[j]);
                } else {
                    pal[i][j] = (str[i] == str[j]) && pal[i+1][j-1];
                }
            }
        }
        
        for(int i=0; i<n; i++) {
            if(pal[0][i] == true)
                dp[i] = 0;
            else {
                dp[i] = INT_MAX;
                
                for(int j=0; j<i; j++) {
                    if(pal[j+1][i] == true && dp[j] < dp[i])
                        dp[i] = dp[j]+1;
                }
            }
        }
        
        return dp[n-1];
    }
};
