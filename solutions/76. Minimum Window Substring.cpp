class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() or t.empty())
            return "";
        
        int count = t.size();
        int require[128] = {0};
        bool chSet[128] = {false};
        
        for (int i = 0; i < count; ++i) {
            require[t[i]]++;
            chSet[t[i]] = true;
        }
        
        int i = -1;
        int j = 0;
        int minLen = INT_MAX;
        int minIdx = 0;
        
        while (i < (int)s.length() && j < (int)s.length()) {
            if (count) {
                i++;
                
                require[s[i]]--;
                
                if (chSet[s[i]] && require[s[i]] >= 0)
                    count--;
            } else {
                if (minLen > i - j + 1) {
                    minLen = i - j + 1;
