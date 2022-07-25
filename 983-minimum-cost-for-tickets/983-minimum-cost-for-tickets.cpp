class Solution {
    int find(int n, int ind, vector<int> &days, vector<int> &cost, vector<int> &dp)
    {
        if(ind >= n) return 0;
      //1day
        
        if(dp[ind] != -1) return dp[ind];
        int option1 = cost[0] + find(n, ind+1, days, cost, dp);
        
        //7day
        int i;
        for(i = ind; i < n && days[i] < days[ind] + 7; i++);
        
        int option2 = cost[1] + find(n, i, days, cost, dp);
        //30days
        for(i = ind; i < n && days[i] < days[ind] + 30; i++);
        
        int option3 = cost[2] + find(n, i, days, cost, dp);
        
        return dp[ind] = min(option1, min(option2, option3));
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
       int n = days.size();
        vector<int> dp(n, -1);
        return find(n, 0, days, costs, dp);
    }
};