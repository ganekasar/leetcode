class Solution {
public:
    string convert(string s, int numRows) {
        
        if(numRows == 1)
            return s;
        
        vector<string> rows(numRows);
        int currRow = 0, dir = 1;
        
        for(char ch : s) {
            rows[currRow].push_back(ch);
            
            if(currRow == 0)
                dir = 1;
            else if(currRow == numRows-1)
                dir = -1;
            
            currRow += dir;
        }
        
        string answer;
        
        for(string str : rows)
            answer += str;
        
        return answer;
    }
};
