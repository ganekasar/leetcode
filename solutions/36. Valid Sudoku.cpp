class Solution {
    
    void reset(vector<bool>& visited) {
        for(bool& x : visited)
            x = false;
    }
    
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<bool> visited(10, false);
        
        for(int row = 0; row < 9; row++) {
            reset(visited);
            
            for(int col = 0; col < 9; col++) {
                if(board[row][col] == ' ')
                    continue;
                
                int index = board[row][col] - '0';
                
                if(visited[index])
                    return false;
                
                visited[index] = true;
            }
        }
        
        
    }
};
