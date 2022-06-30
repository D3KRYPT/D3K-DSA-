class Solution {
public:
    int stepsi[4] = {1, -1, 0, 0};
    int stepsj[4] = {0, 0, -1, 1};
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dpMat(n, vector<int>(m, 0));
        
        int maxi = 1;
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                maxi = max(maxi, longPath(i, j, matrix, dpMat, n, m));
            }
        }
        return maxi;
    }
    
    int longPath(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dpMat, int n, int m)
    {
        int len = 1;
       if(i < 0 || j < 0 || i >= n || j >= m)
       {
           return 0;
       }
        if(dpMat[i][j] > 0)
             return dpMat[i][j];
        
        if(i + 1 < n && i + 1 >= 0 && matrix[i + 1][j] > matrix[i][j])
        {
            len = max(len, 1 + longPath(i + 1, j, matrix, dpMat, n, m));
        }
        
         if(j + 1 < m && j + 1 >= 0 && matrix[i][j + 1] > matrix[i][j])
        {
            len = max(len, 1 + longPath(i, j + 1, matrix, dpMat, n, m));
        }
        
         if(i - 1 < n && i - 1 >= 0 && matrix[i - 1][j] > matrix[i][j])
        {
            len = max(len, 1 + longPath(i - 1, j, matrix, dpMat, n, m));
        }
        
        if(j - 1 < m && j - 1 >= 0 && matrix[i][j - 1] > matrix[i][j])
        {
            len = max(len, 1 + longPath(i, j - 1, matrix, dpMat, n, m));
        }
        
        dpMat[i][j] = len;
        
        return len;
        
    }
};