class Solution {
public:
    
    bool isValid(char a, char b) {
        if(a <= '1')
            return true;
        
        if(a == '2' && b <= '6')
            return true;
        
        return false;
    }
    
    int numDecodings(string s) {
        int n = s.length();
        int curr, prev = 1, p_prev = 0;
        
        for(int i = n-1; i >= 0; i--) {
            if(s[i] == '0')
                curr = 0;
            else {
                curr = prev;
                
                if(i < n-1 && isValid(s[i], s[i+1]))
                    curr += p_prev;
            }
            p_prev = prev;
            prev = curr;
        }
        
        return prev;
    }
};
