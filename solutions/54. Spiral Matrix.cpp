class Solution {
    
    vector<pair<int,int>> dxy = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    
    bool isValid(int x, int y, int ROWS, int COLS) {
        return x >= 0 && y >= 0 && x < ROWS && y < COLS;
    }
    
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> answer;
        int ROWS = matrix.size(), COLS = matrix[0].size();
        int changeIndex = 0;
        
        int x = 0, y = 0;
        
        while(answer.size() < ROWS*COLS) {
            if(!isValid(x, y, ROWS, COLS) or matrix[x][y] == 101) {
                x -= dxy[changeIndex].first;
                y -= dxy[changeIndex].second;
                
                changeIndex = (changeIndex + 1) % 4;
            } else {
                answer.push_back(matrix[x][y]);
                matrix[x][y] = 101;
            }
            
            x += dxy[changeIndex].first;
            y += dxy[changeIndex].second;
        } 
        
        return answer;
    }
};
