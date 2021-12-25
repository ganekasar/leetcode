class Solution {
public:
    
    void solve(vector<string>& combinations, string curr, int count, int n) {
        if(curr.length() == 2*n) {
            if(count == 0)
                combinations.push_back(curr);
            return;
        }
        
        if(count > 0)
            solve(combinations, curr + ")", count - 1, n);
        
        solve(combinations, curr + "(", count + 1, n);
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> combinations;
        string curr;
        solve(combinations, curr, 0, n);
        return combinations;
    }
};
