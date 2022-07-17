class Solution {
public:
    int longestPalindromeSubseq(string s)
    {
        int a = s.length();
        vector<vector<int>> dp(a+1, vector<int> (a+1, 0));
        string t = s;
        reverse(t.begin(), t.end());
        //cout << t;
        
        int langthMax = 0;
        for(int i = 1; i <= a; i++)
        {
            for(int j = 1; j <= a; j++)
            {
            if(s[i - 1] == t[j - 1]) 
            {
                dp[i][j] =  1 + dp[i - 1][j - 1];
            }
                
              else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);   
            }
        }
        
        return dp[a][a];
    }
};