class Solution {
public:
    int findLCS(string &a, string &t, int i, int j, vector<vector<int>> &dp)
  {
      if(i < 0 || j < 0) return 0;
      
      if(dp[i][j] != -1) return dp[i][j];
      if(a[i] == t[j]) return dp[i][j] =  1 + findLCS(a, t, i - 1, j - 1, dp);
      return dp[i][j] = max(findLCS(a, t, i, j - 1, dp), findLCS(a, t, i - 1, j, dp));
  }
    int longestPalindromeSubseq(string s) {
        int a = s.length();
        vector<vector<int>> dp(a, vector<int> (a, -1));
        string t = s;
        reverse(t.begin(), t.end());
        //cout << t;
        return findLCS(s, t, a - 1, a - 1, dp);
    }
};