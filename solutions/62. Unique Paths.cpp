class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> pathsCount(m, vector<int>(n, 0));
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0 or j == 0)
                    pathsCount[i][j] = 1;
                else
                    pathsCount[i][j] = pathsCount[i-1][j] + pathsCount[i][j-1];
            }
        }
        
        return pathsCount[m-1][n-1];
    }
};
