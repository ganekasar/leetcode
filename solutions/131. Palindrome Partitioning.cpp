class Solution {
public:
    
    bool isPalindrome(string str, int low, int high) {
        while(low < high) {
            if(str[low] != str[high])
                return false;
            low++;
            high--;
        }
        
        return true;
    }
    
    void allPalPartRec(vector<vector<string>>& allPart, vector<string>& currPart, int start, int n, string str) {
        if(start >= n) {
            allPart.push_back(currPart);
            return;
        }
        
        for(int i = start; i < n; i++) {
            if(isPalindrome(str, start, i)) {
                currPart.push_back(str.substr(start, i-start+1));
                allPalPartRec(allPart, currPart, i+1, n, str);
                currPart.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        
        int n = s.length();
        
        vector<vector<string>> allPart;
        
        if(n == 0)
            return allPart;
        
        vector<string> currPart;
        
        allPalPartRec(allPart, currPart, 0, n, s);
        
        return allPart;
    }
};
