class Solution {
    bool find (int ind, int target, vector<int>& arr, vector<vector<int>> &dp)
    {
        if(target == 0) return true;
        if(ind == 0) return target == arr[ind];
        
        if(dp[ind][target] != -1) return dp[ind][target];
        bool notPick = find(ind - 1, target, arr, dp);
        bool pick = false;
        if(target >= arr[ind])
        {
            pick = find(ind - 1, target - arr[ind], arr, dp);
        }
        
        return dp[ind][target] = pick or notPick;
    }
public:
    bool canPartition(vector<int>& arr) {
        int n = arr.size();
        int sum = 0;
        for(int i = 0; i < n; i++)
            sum += arr[i];
            
        if(sum % 2) return false;
        
        int target = sum / 2;
        vector<vector<int>> dp(n, vector<int>(target+1, -1));
        
       return find(n-1, target, arr, dp);
    }
};