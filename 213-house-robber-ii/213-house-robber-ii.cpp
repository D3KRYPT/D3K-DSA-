class Solution {
private: 
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
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 1) return nums[0];
        
        vector<int> temp1, temp2;
        vector<int> dp(n, -1);
        for(int i = 0; i < n; i++)
        {
            if(i != 0) temp1.push_back(nums[i]);
            if(i != n - 1) temp2.push_back(nums[i]);
        }
        
        return max(calculate(n - 2, temp1, dp), calculate(n - 2, temp2, dp));
    }
};