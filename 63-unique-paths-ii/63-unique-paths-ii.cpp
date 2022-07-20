class Solution {
private: 
    int findPaths(int i, int j, vector<vector<int>> &g, vector<vector<int>> &dp)
    {
        if(i >= 0 && j >= 0 && g[i][j] == 1) return 0;
        if(i == 0 && j == 0) return 1;
        if(i < 0 or j < 0) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        int up = findPaths(i - 1, j, g, dp);
        int left = findPaths(i, j-1, g, dp);
        
        
        return dp[i][j] = up + left;        
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        return findPaths(n-1 , m-1, obstacleGrid, dp);
    }
};