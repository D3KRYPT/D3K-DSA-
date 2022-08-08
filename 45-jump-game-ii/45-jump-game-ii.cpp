class Solution {
    private:
    int find(int ind, vector<int> &nums, int n, vector<int> &dp)
    {
        if(ind >= n - 1) return 0;
        
        int temp = 1e9;
        
        for(int i = 1; i <= nums[ind]; i++)
        {
            if(dp[ind] != -1) return dp[ind];
            temp = min(temp, 1 + find(ind + i, nums, n, dp));
        }
        return dp[ind] = temp;
    }
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return find(0, nums, n, dp);
    }
};