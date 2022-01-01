class Solution {
    
    vector<int> dp;
    
    bool solve(string& s, vector<string>& wordDict, int startIndex) {
        if(startIndex == s.length()) 
            return true;
        
        if(dp[startIndex] != -1)
            return dp[startIndex];
        
        bool result = false;
        string currStr;
        
        for(int i = startIndex; i < s.length(); i++) {
            currStr.push_back(s[i]);
            
            if(binary_search(wordDict.begin(), wordDict.end(), currStr))
                result = result or solve(s, wordDict, i+1);
        }
        
        return dp[startIndex] = result;
    }
    
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        dp.resize(n, -1);
        sort(wordDict.begin(), wordDict.end());
        return solve(s, wordDict, 0);
    }
};
