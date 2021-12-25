class Solution {
public:
    
    map<string,bool> dp;
    
    bool isScramble(string s1, string s2) {
        
        if (s1.length() != s2.length())  
            return false; 
  
        int n = s1.length(); 
​
        if (n == 0) 
            return false; 
​
        if (s1 == s2) 
            return true;  
​
        string copy_s1 = s1, copy_s2 = s2; 
​
        sort(copy_s1.begin(), copy_s1.end()); 
        sort(copy_s2.begin(), copy_s2.end()); 
​
        if (copy_s1 != copy_s2) 
            return false;  
        
        if(n <= 3)
            return true;
        
        string key = s1 + " " + s2;
        
        if(dp.find(key) != dp.end())
            return dp[key];
​
        for (int i = 1; i < n; i++) { 
​
            if (isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i, n - i), s2.substr(i, n - i))) {
                dp[key] = true;
                return true; 
            }
​
            if (isScramble(s1.substr(0, i), s2.substr(n - i, i)) && isScramble(s1.substr(i, n - i), s2.substr(0, n - i))) {
                dp[key] = true;
                return true;
            }
        }
        
        dp[key] = false;
​
        return false; 
    }
};
