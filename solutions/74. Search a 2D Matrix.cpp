class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int ROWS = matrix.size();
        int COLS = matrix[0].size();
        
        int x = 0, y = COLS-1;
        
        while(x < ROWS && y >= 0) {
            if(matrix[x][y] == target)
                return true;
            else if(matrix[x][y] < target)
                x++;
            else if(matrix[x][y] > target)
                y--;
        }
        
        return false;
    }
};
