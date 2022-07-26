//buy -> 0 ---i cannot buy
class Solution {
    int find(int ind, vector<int> &prices, int buy, int n, vector<vector<int>> &dp)
    {
        if(ind >= n)return 0;   
        int profit = 0;
        if(dp[ind][buy] != -1) return dp[ind][buy];
        if(buy != 0)
        {
            profit = max(-prices[ind] + find(ind+1, prices, 0, n, dp),
                         0 + find(ind+1, prices, 1, n, dp));
        }
        else{
            profit = max(prices[ind] + find(ind + 1, prices, 1, n, dp), 0 + find(ind+1, prices,0, n, dp));
        }
        
        return dp[ind][buy] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int> (2, -1));
        return find(0, prices, 1, n, dp);
    }
};