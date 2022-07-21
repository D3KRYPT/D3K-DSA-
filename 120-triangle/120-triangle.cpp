class Solution {
private:
    int find(int i, int j, vector<vector<int>> &t, int n, vector<vector<int>> &dp)
    {
        if(i == n-1) return t[n-1][j];
        
        if(dp[i][j] != -1) return dp[i][j];
        int d = t[i][j] + find(i+1, j, t, n, dp);
        int g = t[i][j] + find(i+1, j+1, t, n, dp);
        
        return dp[i][j] = min(d, g);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return find(0, 0, triangle, n, dp);
    }
};