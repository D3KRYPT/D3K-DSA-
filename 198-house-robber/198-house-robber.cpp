class Solution {
public:
    int  calculate(int ind, vector <int> &nums, vector <int> &dp)
    {
        int n = nums.size();
        dp[0] = nums[0];
        int neg = 0;
        
        for(int i = 1; i < n; i++)
        {
            int rob = nums[i];
            if(i > 1) rob += dp[i - 2];
            
            int notRob = dp[i - 1];
            
            dp[i] = max(rob, notRob);
        }
        return dp[n-1];
    }
    
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        vector <int> dp(n, -1); 
        
       return calculate(n - 1, nums, dp);
        
    }
};