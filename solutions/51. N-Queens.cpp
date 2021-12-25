class Solution {
    vector<vector<string>> solutions;    
public:
    
    bool can_place(int row, int col, int n, vector<string>& grid) {
        for(int i = 0; i < row; i++) {
            if(grid[i][col] == 'Q')
                return false;
        }
        
        for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if(grid[i][j] == 'Q')
                return false;
        }
        
        for(int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if(grid[i][j] == 'Q')
                return false;
        }
        
        return true;
    }
    
    void solveNQueensRec(int row, int n, vector<string>& grid) {
        if(row == n) {
            solutions.push_back(grid);
            return;
        }
        
        for(int col = 0; col < n; col++) {
            if(can_place(row, col, n, grid)) {
                grid[row][col] = 'Q';
                solveNQueensRec(row + 1, n, grid);
                grid[row][col] = '.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<string> grid(n);
        
        for(int i = 0; i < n; i++) 
            for(int j = 0; j < n; j++) 
                grid[i].push_back('.');
        
        solveNQueensRec(0, n, grid);
        
        return solutions;
        
    }
};
