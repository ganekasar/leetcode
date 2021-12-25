class Solution {
public:
    int numDistinct(string s, string t) {
        int m = t.length(), n = s.length();
        vector<long long> dp(m + 1, 0);
        
        dp[0] = 1;
        
        for (int j = 1; j <= n; j++) { 
            int pre = 1;
            for (int i = 1; i <= m; i++) {
                long long temp = dp[i];
                dp[i] +=(t[i - 1] == s[j - 1] ? pre : 0);
                pre = temp;
            }
        }
        
        return (int)dp[m];
    }
};
