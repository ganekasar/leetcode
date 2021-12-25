class Solution {
public:
    bool isNumber(string s) {
        int n = s.size();
        int i = 0;
        int count_num = 0, count_point = 0;
        
        while(s[i] == ' ') 
            i++;
        
        if(s[i] == '+' or s[i] == '-') 
            i++;
        
        while(isdigit(s[i]) or s[i] == '.') {
            s[i] == '.' ? count_point++ : count_num++;
            i++;
        }
        
        if(count_point > 1 or count_num < 1) 
            return false;
        
        if(s[i] == 'e' or s[i] == 'E') {
            i++;
            count_num = 0;
            count_point = 0;
            
            if(s[i] == '+' or s[i] == '-') 
                i++;
            
            while(isdigit(s[i]) or s[i] == '.') {
                s[i] == '.' ? count_point++ : count_num++;
                i++;
            }
            
            if(count_point > 0 or count_num < 1) 
                return false;
        }
        
        while(s[i] == ' ') 
            i++;
        
        return (i == n);
    }
};
