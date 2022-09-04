class Solution {
   int M = 1e9+7;
    int find(int endpos, int k, int sum, vector<vector<int>> &dp)
    {
        if(k == 0)
        {
            if(sum == endpos)
                return 1;
            else
                return 0;
        }
        
        //if(abs(sum - endpos) > k) return 0;
        
        if(dp[sum + 2000][k] != -1)
            return dp[sum + 2000][k] % M;
        
        int goleft = find(endpos, k - 1, sum - 1, dp) % M;
        
        int goright = find(endpos, k - 1, sum + 1, dp) % M;
        
        return dp[sum + 2000][k] = (goleft + goright) % M;
    }
public:
    int numberOfWays(int startPos, int endPos, int k) {
        
        vector<vector<int>> dp(4001, vector<int>(k +10, -1));
        return find( endPos, k, startPos, dp);
    }
};