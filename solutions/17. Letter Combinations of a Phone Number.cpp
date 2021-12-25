class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) 
            return {};
        
        vector<string> words = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        deque<string> dq;
        
        dq.push_back("");
​
        for(char digit : digits) {
            int d = digit - '0';
            
            for (int i = dq.size(); i > 0; i--) {
                string token = dq.front();
                dq.pop_front();
                
                for (char ch : words[d]) 
                    dq.push_back(token + ch);
            }
        }
​
        return vector<string>(dq.begin(), dq.end());
    }
};
