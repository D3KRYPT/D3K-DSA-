class Solution {
public:
    int  calculate(int ind, vector <int> &nums, vector <int> &dp)
    {
        if(ind == 0) return nums[0];
        if(ind < 0)  return 0;
        
        if(dp[ind] != -1) return dp[ind];
        
        int rob = nums[ind] + calculate(ind - 2, nums, dp);
        int notRob = calculate(ind - 1, nums, dp);
        
        return dp[ind] = max(rob, notRob);
    }
    
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        vector <int> dp(n, -1); 
        
       return calculate(n - 1, nums, dp);
        
    }
};