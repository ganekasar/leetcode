class Solution {
public:
    int longestValidParentheses(string s) {
        int N = s.size();
    
        if (N <= 1) 
            return 0; 
​
        int answer = 0; 
​
        vector<int> dp(N, 0); 
​
        for(int i = 1; i < N; i++) { 
            if (s[i] == ')' && (i - dp[i-1] - 1) >= 0 && s[i - dp[i-1] - 1] == '(') { 
                dp[i] = dp[i-1] + 2;
​
                if(i - dp[i-1] - 2 >= 0)
                    dp[i] += dp[i - dp[i-1] - 2];
​
                answer = max(answer, dp[i]); 
            } 
        } 
        
        return answer; 
    }
};
