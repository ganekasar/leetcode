class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();
        
        for(int x = 0; x < ROWS; x++) {
            for(int y = 0; y < COLS; y++) {
                if(x == 0 && y == 0)
                    continue;
                else if(x == 0)
                    grid[x][y] += grid[x][y-1];
                else if(y == 0)
                    grid[x][y] += grid[x-1][y];
                else
                    grid[x][y] += min(grid[x-1][y], grid[x][y-1]);
            }
        }
        
        return grid[ROWS-1][COLS-1];
    }
};
