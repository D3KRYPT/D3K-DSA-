class Solution {
private:
    int find(int ind, vector<int> &coins, int targ, vector<vector<int>> &dp)
    {   //if(targ == 0) return 1;
        if(ind == 0)
        {
            if(targ % coins[0] == 0) 
                return targ / coins[0];
            else
                return 1e9;
        }
        
        if(dp[ind][targ] != -1) return dp[ind][targ];
        int notTake = 0 + find(ind-1, coins, targ, dp);
        int take = INT_MAX;
        if(targ >= coins[ind])
        {
            take = 1 + find(ind, coins, targ - coins[ind], dp);
        }
        return dp[ind][targ] = min(take, notTake);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        int ans = find(n-1, coins, amount, dp);
        if(ans == 1e9)return -1;
        return ans;
        
    }
};