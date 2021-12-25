class Solution {
    
    int ROWS, COLS;
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};
    
    bool isValid(int x, int y) {
        return x >= 0 && y >= 0 && x < ROWS && y < COLS;
    }
    
    bool dfs(vector<vector<char>>& board, string& word, int x, int y, int index, vector<vector<bool>>& visited) {
        if(board[x][y] != word[index])
            return false;
        
        if(index == word.length() - 1)
            return true;
        
        visited[x][y] = true;
        
        for(int i = 0; i < 4; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];
            
            if(isValid(newX, newY) && !visited[newX][newY]) {
                if(dfs(board, word, newX, newY, index+1, visited))
                    return true;
            }
        }
        
        visited[x][y] = false;
        
        return false;
    }
    
public:
    bool exist(vector<vector<char>>& board, string word) {
        ROWS = board.size();
        COLS = board[0].size();
        
        vector<vector<bool>> visited(ROWS, vector<bool>(COLS, false));
        
        for(int i = 0; i < ROWS; i++) {
            for(int j = 0; j < COLS; j++) {
                if(dfs(board, word, i, j, 0, visited))
                    return true;
