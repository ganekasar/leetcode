class Solution {
public:
    
    vector<int> prefixFunction(string s, int sLength) {
        vector<int> lps(sLength, 0);
        
        for(int i = 1; i < sLength; i++) {
            int j = lps[i-1];
            
            while(j > 0 && s[i] != s[j])
                j = lps[j-1];
            
            if(s[i] == s[j])
                lps[i] = j+1;
            else
                lps[i] = j;
        }
        
        return lps;
    }
    
    int strStr(string haystack, string needle) {
        int haystackLength = haystack.length();
        int needleLength = needle.length();
        
        if(haystackLength == 0 && needleLength == 0)
            return 0;
        else if(needleLength == 0)
            return 0;
        else if(haystackLength == 0)
            return -1;
            
        string str = needle + "#" + haystack;
        
        int strLength = str.length();
        
        vector<int> lps = prefixFunction(str, strLength);
        
        for(int i = needleLength + 1; i < strLength; i++) {
            if(lps[i] == needleLength)
                return i - 2*needleLength;
        }
        
        return -1;
    }
