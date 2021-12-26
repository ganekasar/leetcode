class Solution {
public:
    bool isPalindrome(string s) {
        string newStr;
        
        for(char ch : s) {
            if(ch >= 'a' && ch <= 'z')
                newStr.push_back(ch);
            else if(ch >= 'A' && ch <= 'Z') {
                ch = (char)ch + 32;
                newStr.push_back(ch);
            } else if(ch >= '0' && ch <= '9')
                newStr.push_back(ch);
        }
        
        for(int i = 0, j = newStr.length()-1; i < j; i++, j--) {
            if(newStr[i] != newStr[j])
                return false;
        }
        
        return true;
    }
};
