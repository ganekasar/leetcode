class Solution {
public:
    
    bool canPlace(vector<vector<int>>& grid, int row, int col, int n) {
        for(int i = 0; i < row; i++) {
            if(grid[i][col] == 1)
                return false;
        }
        
        for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if(grid[i][j] == 1)
                return false;
        }
        
        for(int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if(grid[i][j] == 1)
                return false;
        }
        
        return true;
    }
    
    int solve(vector<vector<int>>& grid, int row, int n) {
        if(row == n)
            return 1;
        
        int result = 0;
        
        for(int col = 0; col < n; col++) {
            if(canPlace(grid, row, col, n)) {
                grid[row][col] = 1;
                result += solve(grid, row + 1, n);
                grid[row][col] = 0;
            }
        }
        
        return result;
    }
    
    int totalNQueens(int n) {
        vector<vector<int>> grid(n, vector<int>(n, 0));
        int answer = solve(grid, 0, n);
        return answer;
    }
};
