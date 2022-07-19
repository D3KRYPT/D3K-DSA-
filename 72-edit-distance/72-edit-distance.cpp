class Solution {
private:
    int find(int n, int m, string &s, string &t, vector<vector<int>> &dp)
    {
        if(n == 0) return m ;
        if(m == 0) return n;
        if(dp[n][m] != -1) return dp[n][m];
        
        if(s[n-1] == t[m-1]) return dp[n][m] = 0 + find(n - 1, m - 1, s, t, dp);
        return dp[n][m] = 1 +  min(find(n, m - 1, s, t, dp), min (find(n - 1, m, s, t, dp), find(n - 1, m - 1, s, t, dp)));
    }
public:
    int minDistance(string s, string t) {
        
        int n = s.length();
        int m = t.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return find(n, m , s, t, dp);
        
        
    }
};