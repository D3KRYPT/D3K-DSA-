class Solution {
private:
    int findMin(int i, int j, vector<vector<int>>& m, int n,  vector<vector<int>> &dp)
    {
        
        
        if(j < 0 || j >= n) return 1e9;
        if(i == 0) return m[0][j];
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int up = m[i][j] + findMin(i - 1, j, m, n, dp);
        int ld = m[i][j] + findMin(i - 1, j - 1, m ,n, dp);
        int rd = m[i][j] + findMin(i - 1, j + 1, m , n, dp);
        
        return dp[i][j] = min(up, min(ld, rd));
    }
public:
    int minFallingPathSum(vector<vector<int>>& m) {
        int i = m.size();
        int j = m[0].size();
        vector<vector<int>> dp(i, vector<int>(j, -1));
       //return findMin(i - 1, j - 1, m, j);
        int mini = 99999;
        for(int k = 0; k <= j; k++)
        {
            mini = min(mini, findMin(i-1, k, m, j, dp));
        }
        return mini;
    }
};