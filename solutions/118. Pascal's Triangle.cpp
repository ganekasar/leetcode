class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascal;
        
        for(int i = 0; i < numRows; i++) {
            vector<int> curr;
            for(int j = 0; j <= i; j++) {
                if(j == 0 or j == i)
                    curr.push_back(1);
                else 
                    curr.push_back(pascal[i-1][j-1] + pascal[i-1][j]);
            }
            pascal.push_back(curr);
        }
        
        return pascal;
    }
};
