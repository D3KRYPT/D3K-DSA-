class Solution {
private:
    bool find(int pointer, int n, vector <int> &nums, vector<int> &dp)
    {
        if(pointer == n - 1)
            return true;
        
        if(dp[pointer] != -1)
            return dp[pointer];
        
        for(int i = 1; i <= nums[pointer]; i++)
        {
            if(find(pointer + i, n, nums, dp))
            {
                //cout << cnt << " ";
                return dp[pointer] = true;
            }
        }
        
        return dp[pointer] = false;
    }
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int pointer = 0, curr = 0,cnt = 0;
        vector<int> dp(n, -1);
        bool ans = find(pointer, n, nums, dp);
        cout << cnt;
        return ans;
    }
};