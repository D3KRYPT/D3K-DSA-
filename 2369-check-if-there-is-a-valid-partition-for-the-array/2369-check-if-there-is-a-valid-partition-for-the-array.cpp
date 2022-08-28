class Solution {
public:
    bool find(vector<int> &nums, int ind, vector <int> &dp)
    {
        
        int n = nums.size();
        
        if(ind == n) return true;
        
        if(dp[ind] != -1) 
            return dp[ind];
        
        if(ind + 1 < n && nums[ind] == nums[ind + 1])
        {
            if(find(nums, ind + 2, dp))
            {
                return true;
            }
            
            if(ind + 2 < n && nums[ind] == nums[ind + 2])
            {
                if(find(nums, ind + 3, dp))
                { 
                    return true;
                }
            }
        }
        
        if( ind + 2 < n && nums[ind + 1] == nums[ind] + 1 && nums[ind + 2] == nums[ind] + 2)
        {
            if(find(nums, ind + 3, dp))
                return true;
        }
        
        return dp[ind] = false; 
    }
    bool validPartition(vector<int>& nums) {
        
        int n = nums.size();
        vector <int> dp(n, -1);
       return find(nums, 0, dp);
    }
};